#include "PackageReader.h"
#include <stdio.h>
#include <cstring>
#include <algorithm>


PackageReader::PackageReader()
	:m_Buff{ 0 }
{
	m_Data = m_Buff;
	m_Length = 0;
}
PackageReader::~PackageReader()
{
	m_Data = nullptr;
	m_Length = 0;
}
void PackageReader::Reset()
{
	m_Data = m_Buff;
	m_Length = 0;
}
void PackageReader::PopFront(unsigned int len)
{
	len = std::min(len, m_Length);
	m_Length = m_Length - len;
	if (m_Length > 0)
	{
		std::memmove(m_Buff, m_Data + len, m_Length);
	}
	m_Data = m_Buff;
}
char* PackageReader::Data()
{
	return m_Data;
}
int PackageReader::Length()
{
	return m_Length;
}
char* PackageReader::Tail()
{
	return m_Data + m_Length;
}
unsigned int PackageReader::TailSize()
{
	return unsigned((m_Buff + MaxPackageSize) - (m_Data + m_Length));
}
void PackageReader::Shift(unsigned int len)
{
	m_Data += len;
	m_Length -= len;
}
unsigned int PackageReader::Append(char* data, unsigned int len)
{
	len = std::min(len, TailSize());
	memcpy(Tail(), data, len);
	m_Length += len;
	return len;
}
