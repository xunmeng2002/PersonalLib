#pragma once
#include "StepPackageBase.h"

namespace step
{
	class StepSubscriber
	{
	public:
		virtual void OnStepConnect(SessionIDType sessionID, const char* ip, int port) {}
		virtual void OnStepDisConnect(SessionIDType sessionID, const char* ip, int port) = 0;
		virtual void OnStepMessage(StepPackageBase* stepPackage) = 0;
	};
}


