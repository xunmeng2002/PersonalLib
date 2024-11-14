#pragma once
#include "XtpPackageBase.h"

namespace xtp
{
	class XtpPackageFactoryBase
	{
	public:
		static XtpPackageFactoryBase* Create();
		virtual XtpPackageBase* CreateXtpPackage(UShortType packageID) = 0;
	};
}


