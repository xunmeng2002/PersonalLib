#pragma once
#include "Types.h"

namespace step
{
	//报文头
	class StepHeadField
	{
	public:
		static constexpr UShortType FieldID = 0x0001;
		UShortType PackageID;		//报文代码,报文唯一编号tag = 3固定长度5位
		UShortType BodyLen;		//报文长度tag = 2固定长度5位
		BoolType MessageChain;		//报文链标记tag = 4固定长度1位
		IntType MsgSeqNum;		//请求编号tag = 5固定长度10位
	};
	//报文尾
	class StepTailField
	{
	public:
		static constexpr UShortType FieldID = 0x0002;
		UShortType CheckSum;		//校验和tag = 6固定长度3位
	};
}
