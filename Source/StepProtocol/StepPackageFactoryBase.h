#pragma once
#include "StepPackageBase.h"

namespace step
{
	class StepPackageFactoryBase
	{
	public:
		virtual StepPackageBase* CreateStepPackage(UShortType packageID) = 0;
	};
}
