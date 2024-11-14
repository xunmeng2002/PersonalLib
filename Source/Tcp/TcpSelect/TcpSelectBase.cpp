#include "TcpSelectBase.h"
#include "Logger.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectBase::TcpSelectBase()
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
	m_SelectSocketTimeOut.tv_sec = 0;
	m_SelectSocketTimeOut.tv_usec = 100 * 1000;
	m_SelectSocketTimeOutTemp.tv_sec = 0;
	m_SelectSocketTimeOutTemp.tv_usec = 100 * 1000;
}
void TcpSelectBase::SetSelectTimeOut(int milliSeconds)
{
	m_SelectSocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SelectSocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
	memcpy(&m_SelectSocketTimeOutTemp, &m_SelectSocketTimeOut, sizeof(timeval));
}
