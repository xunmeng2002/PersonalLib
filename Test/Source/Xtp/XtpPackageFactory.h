#pragma once
#include "XtpPackageFactoryBase.h"



namespace xtp
{
	class XtpPackageFactory : public XtpPackageFactoryBase
	{
		virtual XtpPackageBase* CreateXtpPackage(UShortType packageID) override;
	};
}
