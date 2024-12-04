#pragma once
#include "Package.h"
#include "Head.h"
#include "StepUtility.h"


namespace step
{
	class StepPackageBase : public Package
	{
	public:
		StepPackageBase();
		virtual void Prepare(SessionIDType sessionID, bool messageChain, int msgSeqNum) = 0;
		int MakePackage(char* buff, int size);

		virtual int ToProtocolStream(char* buff, int size) const = 0;
		virtual bool FromProtocolStream(char* buff, int startIndex, int endIndex) = 0;
		virtual const char* GetDebugString() const = 0;

		HeadField Head;
		TailField Tail;
	};
}

