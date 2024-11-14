#include "ShmBase.h"
#include "Logger.h"
#include "TimeUtility.h"
#ifdef WINDOWS
#include "Windows.h"
#endif
#ifdef LINUX
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#endif

using namespace std;

ShmBase::ShmBase(ServerTypeType shmType, const char* threadName, const char* shmName)
	:IOThread(threadName, shmName), m_ShmType(shmType), m_CommonShmHeader(nullptr), m_ShmAddr(nullptr)
{
#ifdef WINDOWS
	m_File = nullptr;
	m_FileMap = nullptr;
#endif // WINDOWS

	auto index = m_AddressName.find(':');
	m_ShmName = m_AddressName.substr(0, index);
	m_MaxConnectSize = atoi(m_AddressName.substr(index + 1).c_str());

	m_Sem = new Sem((m_ShmName + "Sem").c_str());
}
ShmBase::~ShmBase()
{
	{
		lock_guard<mutex> guard(m_ShmConnectsMutex);
		for (auto& it : m_ShmConnects)
		{
			auto shmConnect = it.second;
			shmConnect->ShmBuffer->m_ShmHeader->Status--;
			m_IOSubscriber->OnDisConnect(shmConnect->SessionID, m_ShmName.c_str(), std::to_string(shmConnect->Index).c_str());
		}
		m_ShmConnects.clear();
	}

	if (m_Sem != nullptr)
		delete m_Sem;
	m_Sem = nullptr;
#ifdef WINDOWS
	UnmapViewOfFile(m_ShmAddr);
	CloseHandle(m_FileMap);
	if (m_File != nullptr)
	{
		CloseHandle(m_File);
		m_File = nullptr;
	}
	if (m_ShmType == ServerTypeType::Server)
	{
		DeleteFileA(m_ShmName.c_str());
	}
#endif
#ifdef LINUX
	if (munmap(m_ShmAddr, ShmBuffSize * m_MaxConnectSize * 2) < 0)
	{
		perror("shm_unlink");
		WriteLog(LogLevel::Warning, "munmap Failed. ErrNo:%d", errno);
	}
	if (m_ShmType == ServerTypeType::Server)
	{
		if (shm_unlink(m_ShmName.c_str()) < 0)
		{
			perror("shm_unlink");
			WriteLog(LogLevel::Warning, "shm_unlink Failed. ErrNo:%d", errno);
		}
	}
#endif
}
bool ShmBase::Init()
{
	if (!m_Sem->Init())
		return false;
#ifdef WINDOWS
	if (m_ShmType == ServerTypeType::Server)
	{
		m_File = CreateFileA(m_ShmName.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		if (m_File == INVALID_HANDLE_VALUE)
		{
			WriteLog(LogLevel::Warning, "CreateFileA Failed. ErrNo:%d", GetLastError());
			return false;
		}
		m_FileMap = CreateFileMappingA(m_File, NULL, PAGE_READWRITE, 0, ShmBuffSize * m_MaxConnectSize * 2, m_ShmName.c_str());
	}
	else
	{
		m_FileMap = OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, m_ShmName.c_str());
	}
	if (m_FileMap == NULL)
	{
		WriteLog(LogLevel::Warning, "Create Or Open FileMapping Failed. ErrNo:%d", GetLastError());
		return false;
	}
	m_ShmAddr = (char*)MapViewOfFile(m_FileMap, FILE_MAP_ALL_ACCESS, 0, 0, ShmBuffSize * m_MaxConnectSize  *  2);
	if (m_ShmAddr == NULL)
	{
		WriteLog(LogLevel::Warning, "MapViewOfFile Failed. ErrNo:%d", GetLastError());
		return false;
	}
#endif
#ifdef LINUX
	int fd;
	if (m_ShmType == ServerTypeType::Server)
	{
		fd = shm_open(m_ShmName.c_str(), O_CREAT | O_EXCL | O_RDWR, 0666);
	}
	else
	{
		fd = shm_open(m_ShmName.c_str(), O_EXCL | O_RDWR, 0666);
	}
	if (fd < 0)
	{
		WriteLog(LogLevel::Warning, "shm_open Failed. ErrNo:%d", errno);
		return false;
	}
	if (ftruncate(fd, ShmBuffSize * m_MaxConnectSize * 2) == -1)
	{
		WriteLog(LogLevel::Warning, "ftruncate Failed. ErrNo:%d", errno);
		return false;
	}
	m_ShmAddr = (char*)mmap(nullptr, ShmBuffSize * m_MaxConnectSize * 2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (m_ShmAddr == MAP_FAILED)
	{
		WriteLog(LogLevel::Warning, "mmap Failed. ErrNo:%d", errno);
		return false;
	}
#endif
	m_CommonShmHeader = (SingleShmHeader*)m_ShmAddr;
	if (m_ShmType == ServerTypeType::Server)
	{
		memset(m_ShmAddr, 0, ShmBuffSize * m_MaxConnectSize * 2);
	}
	WriteLog(LogLevel::Info, "Create Or Open Shm Successed.");
	return true;
}

void ShmBase::DisConnect(SessionIDType sessionID)
{
	auto shmConnect = GetShmConnect(sessionID);
	lock_guard<mutex> guard(m_ShmDisConnectsMutex);
	m_ShmDisConnects.push_back(shmConnect);
}
int ShmBase::Send(SessionIDType sessionID, const char* data, unsigned len)
{
	auto shmConnect = GetShmConnect(sessionID);
	return shmConnect->ShmBuffer->Write(data, len);
}
int ShmBase::Send(SessionIDType sessionID, Buffer<BuffSize>* buffer)
{
	auto shmConnect = GetShmConnect(sessionID);
	return shmConnect->ShmBuffer->Write(buffer->GetReadPos(), buffer->GetLength());
}

void ShmBase::CheckConnect()
{
	lock_guard<mutex> guard(m_ShmConnectsMutex);
	for (auto& it : m_ShmConnects)
	{
		auto shmConnect = it.second;
		if (shmConnect->ShmBuffer->m_ShmHeader->Status == 1)
		{
			lock_guard<mutex> guard(m_ShmDisConnectsMutex);
			m_ShmDisConnects.push_back(shmConnect);
		}
	}
}
void ShmBase::DoDisConnect()
{
	lock_guard<mutex> guard(m_ShmDisConnectsMutex);
	for (auto shmDisConnect : m_ShmDisConnects)
	{
		RemoveConnect(shmDisConnect);
	}
	m_ShmDisConnects.clear();
}
void ShmBase::HandleEvent()
{
	for (auto& it : m_ShmConnects)
	{
		auto shmConnect = it.second;
		if (shmConnect->ShmBuffer->GetReadBufferSize() > 0)
		{
			DoRecv(shmConnect);
		}
	}
}

void ShmBase::DoRecv(ShmConnect<ShmBuffSize>* shmConnect)
{
	Buffer<BuffSize>* buffer = Buffer<BuffSize>::Allocate();
	auto len = shmConnect->ShmBuffer->Read(buffer->GetData(), BuffSize);
	buffer->SetLength(len);
	if (m_IOSubscriber != nullptr)
		m_IOSubscriber->OnRecv(shmConnect->SessionID, buffer);
	else
		buffer->Free();
}
ShmConnect<ShmBuffSize>* ShmBase::GetShmConnect(SessionIDType sessionID)
{
	std::lock_guard<mutex> guard(m_ShmConnectsMutex);
	if (m_ShmConnects.find(sessionID) != m_ShmConnects.end())
		return m_ShmConnects[sessionID];
	return nullptr;
}
void ShmBase::AddConnect(int index)
{
	ShmConnect<ShmBuffSize>* shmConnect = ShmConnect<ShmBuffSize>::Allocate();
	shmConnect->SessionID = GetSessionID();
	shmConnect->Index = index;
	shmConnect->ShmBuffer = SingleShmBuffer<ShmBuffSize>::Allocate();
	shmConnect->ShmBuffer->m_ShmHeader = m_CommonShmHeader + index;
	shmConnect->ShmBuffer->m_ServerType = m_ShmType;
	shmConnect->ShmBuffer->m_UpBuffer = (char*)m_ShmAddr + ShmBuffSize * index * 2;
	shmConnect->ShmBuffer->m_DownBuffer = (char*)m_ShmAddr + ShmBuffSize * (index * 2 + 1);
	lock_guard<mutex> guard(m_ShmConnectsMutex);
	m_ShmConnects.insert(make_pair(shmConnect->SessionID, shmConnect));

	m_IOSubscriber->OnConnect(shmConnect->SessionID, m_ShmName.c_str(), to_string(index).c_str());
}
void ShmBase::RemoveConnect(ShmConnect<ShmBuffSize>* shmConnect)
{
	m_IOSubscriber->OnDisConnect(shmConnect->SessionID, m_ShmName.c_str(), std::to_string(shmConnect->Index).c_str());
	shmConnect->ShmBuffer->m_ShmHeader->Status--;
	std::lock_guard<mutex> guard(m_ShmConnectsMutex);
	m_ShmConnects.erase(shmConnect->SessionID);
	shmConnect->Free();
}
