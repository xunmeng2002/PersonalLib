#pragma once
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpPackageFactoryBase
	{
	public:
		virtual XtpPackageBase* CreateXtpPackage(UShortType packageID) = 0;
	};
}


