#include "TcpClientBase.h"
#include "Platform.h"
#include "TcpUtility.h"
#include "TimeUtility.h"
#include "Logger.h"


using namespace std;
using namespace std::chrono;

TcpClientBase::TcpClientBase(const char* threadName, const char* addressName)
	:TcpBase(ServerTypeType::Client, threadName, addressName), m_ConnectAddressInfo(nullptr), m_ConnectStatus(false)
{
	ParseIPAddress(m_AddressName, m_ConnectIP, m_ConnectPort);
}
bool TcpClientBase::Init()
{
	return Connect();
}
void TcpClientBase::SetConnectAddress(const char* addressName)
{
	ParseIPAddress(addressName, m_ConnectIP, m_ConnectPort);
}
void TcpClientBase::CheckClientConnect()
{
	if (!m_ConnectStatus)
		Connect();
}
bool TcpClientBase::Connect()
{
	auto ret = GetAddrinfo(m_ConnectIP.c_str(), m_ConnectPort.c_str(), m_ConnectAddressInfo);
	if (ret < 0)
	{
		WriteLog(LogLevel::Info, "GetAddrinfo Failed. IP:[%s] Port[%s] ret[%d] Errno[%d]", m_ConnectIP.c_str(), m_ConnectPort.c_str(), ret, errno);
		return false;
	}
	SOCKET socketID = socket(m_ConnectAddressInfo->ai_family, m_ConnectAddressInfo->ai_socktype, m_ConnectAddressInfo->ai_protocol);
	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, int(m_ConnectAddressInfo->ai_addrlen));
	WriteLog(LogLevel::Info, "Connect Server:IP:[%s] Port[%s] ret[%d]", m_ConnectIP.c_str(), m_ConnectPort.c_str(), ret);
	if (ret < 0)
	{
		WriteLog(LogLevel::Info, "Connect Server Failed. IP:[%s] Port[%s] ret[%d] Errno[%d]", m_ConnectIP.c_str(), m_ConnectPort.c_str(), ret, errno);
		closesocket(socketID);
		return false;
	}
	InitSocket(socketID);
	SessionIDType sessionID = GetSessionID();
	TcpConnect* connectData = TcpConnect::Allocate(sessionID, socketID, m_ConnectIP.c_str(), m_ConnectPort.c_str());
	AddConnect(connectData);

	m_ConnectStatus = true;
	return true;
}
void TcpClientBase::Run()
{
	CheckClientConnect();
	HandleTcpEvent();
}
void TcpClientBase::RemoveConnect(TcpConnect* connectData)
{
	TcpBase::RemoveConnect(connectData);
	m_ConnectStatus = false;
}
