#include "StepPackageFactoryBase.h"
#include "StepPackages.h"
#include "MemCacheTemplateSingleton.h"
#include "Logger.h"
#include <stdio.h>
#include <cstring>


namespace step
{
	class StepPackageFactory : public StepPackageFactoryBase
	{
		virtual StepPackageBase* CreateStepPackage(UShortType packageID) override;
	};
}
