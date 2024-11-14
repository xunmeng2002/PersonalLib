#pragma once
#include "Types.h"

namespace xtp
{
	class XtpHead
	{
	public:
		UShortType PackageID;		//报文代码
		UShortType BodyLen;		//报文长度
	};
	class XtpTail
	{
	public:
		UShortType CheckSum;		//校验和
	};

	short CalculateSum(unsigned char* buff, int len);
}

