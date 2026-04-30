#pragma once
#include "Types/Types.h"

#pragma pack(push, 1)
//报文头
class HeadField
{
public:
	static constexpr UShortType FieldID = 0x0001;
	UShortType PackageID;		//报文代码
	UShortType BodyLen;			//报文长度
	IntType MsgSeqNum;			//请求编号
	IntType MessageChain;		//报文链标记
};
//报文尾
class TailField
{
public:
	static constexpr UShortType FieldID = 0x0002;
	UShortType CheckSum;		//校验和tag = 6固定长度5位
};
#pragma pack(pop)