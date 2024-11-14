#pragma once
#include "StepPackageBase.h"

namespace step
{
	class StepPackageFactoryBase
	{
	public:
		static StepPackageFactoryBase* Create();
		virtual StepPackageBase* CreateStepPackage(UShortType packageID) = 0;
	};
}
