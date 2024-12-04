#include "XtpPackageBase.h"
#include "ProtocolUtility.h"
#include <cstring>


namespace xtp
{
	XtpPackageBase::XtpPackageBase()
		:Package(PackageTypeType::Xtp)
	{
		memset(&Head, 0, sizeof(Head));
		memset(&Tail, 0, sizeof(Tail));
	}
	int XtpPackageBase::MakePackage(char* buff, int size)
	{
		char* data = buff + sizeof(Head);
		Head.BodyLen = ToProtocolStream(data, size - sizeof(Head) - sizeof(Tail));
		memcpy(buff, &Head, sizeof(Head));
		Tail.CheckSum = CalculateSum((unsigned char*)buff, sizeof(Head) + Head.BodyLen);
		memcpy(data + Head.BodyLen, &Tail, sizeof(Tail));

		return sizeof(Head) + Head.BodyLen + sizeof(Tail);
	}
}