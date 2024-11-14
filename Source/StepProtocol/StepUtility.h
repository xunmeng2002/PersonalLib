#pragma once
#include <string>
#include <unordered_map>
#include "Types.h"

namespace step
{
	constexpr unsigned int StepHeaderLen = 36u;
	constexpr unsigned int StepTailLen = 7u;
	constexpr unsigned int SOH = 1u;
	class StepHead
	{
	public:
		static constexpr UShortType FieldID = 0x0001;
		UShortType PackageID;		//报文类别,报文唯一编号tag = 3固定长度5位
		UShortType BodyLen;		//报文长度tag = 2固定长度5位
		BoolType MessageChain;		//报文链标记tag = 4固定长度1位
		IntType MsgSeqNum;		//请求编号tag = 5固定长度10位
	};

	class StepTail
	{
	public:
		static constexpr UShortType FieldID = 0x0002;
		UShortType CheckSum;		//校验和tag = 6固定长度3位
	};


	bool GetNextSoh(char* buff, int startIndex, int endIndex, int& sohIndex);
	bool GetNextEqual(char* buff, int startIndex, int endIndex, int& equalIndex);
	bool GetNext(char* buff, int startIndex, int endIndex, unsigned short& key, std::string& value, int& sohIndex);
	bool GetFieldStart(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldStartIndex);
	bool GetFieldEnd(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldEndIndex);
	bool GetNextFieldZone(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldStartIndex, int& fieldEndIndex);
	bool GetPackageStart(char* buff, int startIndex, int endIndex, int& packageStartIndex);
	
	void WriteString(char*& ppos, int key, bool value);
	void WriteString(char*& ppos, int key, char value);
	void WriteString(char*& ppos, int key, unsigned short value);
	void WriteString(char*& ppos, int key, int value);
	void WriteString(char*& ppos, int key, long long value);
	void WriteString(char*& ppos, int key, double value);
	void WriteString(char*& ppos, int key, std::string value);
	void WriteString(char*& ppos, int key, char* value);
	template<typename T>
	void WriteString(char*& ppos, int key, T value)
	{
		int len = sprintf(ppos, "%d=%s", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteHexString(char*& ppos, int key, unsigned short value);


	void HeadToStream(StepHead* head, char* buff, int size);
	bool HeadFromStream(char* buff, int startIndex, int endIndex, StepHead* head);
	void TailToStream(StepTail* tail, char* buff, int size);
	bool TailFromStream(char* buff, int startIndex, int endIndex, StepTail* tail);
	short CalculateSum(unsigned char* buff, int startIndex, int endIndex);
}