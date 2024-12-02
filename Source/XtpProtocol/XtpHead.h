#pragma once
#include "Types.h"

namespace xtp
{
	//报文头
	class XtpHead
	{
	public:
		static constexpr UShortType FieldID = 0x0001;
		UShortType PackageID;		//报文代码
		UShortType BodyLen;		//报文长度
	};
	//报文尾
	class XtpTail
	{
	public:
		static constexpr UShortType FieldID = 0x0002;
		UShortType CheckSum;		//校验和
	};
}
