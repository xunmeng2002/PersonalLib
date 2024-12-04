#pragma once
#include "Package.h"


namespace step
{
	class StepPackageBase : public Package
	{
	public:
		StepPackageBase();
		virtual int MakePackage(char* buff, int size) override;
	};
}

