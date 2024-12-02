#pragma once
#include "Package.h"
#include "XtpUtility.h"


namespace xtp
{
	class XtpPackageBase : public Package
	{
	public:
		XtpPackageBase();
		virtual void Prepare(SessionIDType sessionID) = 0;
		int MakePackage(char* buff, int size);

		virtual int ToProtocolStream(char* buff, int size) const = 0;
		virtual bool FromProtocolStream(char* buff, int size) = 0;
		virtual const char* GetString() const = 0;
		virtual const char* GetDebugString() const = 0;

		XtpHeadField Head;
		XtpTailField Tail;
	};
}

