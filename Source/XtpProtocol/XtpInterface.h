#pragma once
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpSubscriber
	{
	public:
		virtual void OnXtpConnect(SessionIDType sessionID, const char* ip, const char* port) {}
		virtual void OnXtpDisConnect(SessionIDType sessionID, const char* ip, const char* port) = 0;
		virtual void OnXtpMessage(XtpPackageBase* xtpPackage) = 0;
	};
}


