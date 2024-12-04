#include "StepPackageBase.h"
#include "StepUtility.h"
#include "ProtocolUtility.h"
#include <cstring>


namespace step
{
	StepPackageBase::StepPackageBase()
		:Package(PackageTypeType::Step)
	{
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
	}
	int StepPackageBase::MakePackage(char* buff, int size)
	{
		Head.BodyLen = ToProtocolStream(buff + StepHeaderLen, size - StepHeaderLen - StepTailLen);
		HeadToStream(&Head, buff, StepHeaderLen);
		Tail.CheckSum = CalculateSum((unsigned char*)buff, StepHeaderLen + Head.BodyLen);
		TailToStream(&Tail, buff + StepHeaderLen + Head.BodyLen, StepTailLen);
		return StepHeaderLen + Head.BodyLen + StepTailLen;
	}
}
