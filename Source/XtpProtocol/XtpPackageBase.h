#pragma once
#include "Package.h"


namespace xtp
{
	class XtpPackageBase : public Package
	{
	public:
		XtpPackageBase();
		virtual int MakePackage(char* buff, int size) override;
	};
}

