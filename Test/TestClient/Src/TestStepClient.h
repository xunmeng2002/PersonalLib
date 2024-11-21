#pragma once
#include "TcpBase.h"
#include "StepProtocol.h"


class StepClient : public step::StepProtocol, public step::StepSubscriber
{
public:
	StepClient();
	virtual ~StepClient();

	virtual void OnStepConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnStepDisConnect(SessionIDType sessionID, const char* ip, int port) override;
	virtual void OnStepMessage(step::StepPackageBase* stepPackage) override;

	bool m_Connected;
	SessionIDType m_SessionID;
};



void TestStepClient();


