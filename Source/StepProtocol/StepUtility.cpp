#include "StepUtility.h"
#include "StepItems.h"
#include "Logger.h"

using namespace std;

namespace step
{
	bool GetNextSoh(char* buff, int startIndex, int endIndex, int& sohIndex)
	{
		for (int i = startIndex; i < endIndex; ++i)
		{
			if (buff[i] == SOH)
			{
				sohIndex = i;
				return true;
			}
		}
		return false;
	}
	bool GetNextEqual(char* buff, int startIndex, int endIndex, int& equalIndex)
	{
		for (int i = startIndex; i < endIndex; ++i)
		{
			if (buff[i] == '=')
			{
				equalIndex = i;
				return true;
			}
		}
		return false;
	}
	bool GetNext(char* buff, int startIndex, int endIndex, unsigned short& key, std::string& value, int& sohIndex)
	{
		if (!GetNextSoh(buff, startIndex, endIndex, sohIndex))
		{
			return false;
		}
		int equalIndex = 0;
		if (!GetNextEqual(buff, startIndex, sohIndex, equalIndex))
		{
			return false;
		}
		key = atoi(buff + startIndex);
		value = std::string(buff + equalIndex + 1, buff + sohIndex);
		return true;
	}
	bool GetFieldStart(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldStartIndex)
	{
		for (int i = startIndex; i < endIndex; ++i)
		{
			if (buff[i - 1] == SOH && buff[i] == '6' && buff[i + 1] == '=')
			{
				fieldStartIndex = i;
				fieldID = stoi(buff + i + 2, nullptr, 16);
				return true;
			}
		}
		return false;
	}
	bool GetFieldEnd(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldEndIndex)
	{
		for (int i = startIndex; i < endIndex; ++i)
		{
			if (buff[i - 1] == SOH && buff[i] == '7' && buff[i + 1] == '=')
			{
				fieldID = stoi(buff + i + 2, nullptr, 16);
				int sohIndex = 0;
				if (!GetNextSoh(buff, i, endIndex, sohIndex))
				{
					return false;
				}
				fieldEndIndex = sohIndex + 1;
				return true;
			}
		}
		return false;
	}
	bool GetNextFieldZone(char* buff, int startIndex, int endIndex, unsigned short& fieldID, int& fieldStartIndex, int& fieldEndIndex)
	{
		if (!GetFieldStart(buff, startIndex, endIndex, fieldID, fieldStartIndex))
		{
			return false;
		}
		unsigned short fieldIDEnd;
		if (!GetFieldEnd(buff, startIndex, endIndex, fieldIDEnd, fieldEndIndex))
		{
			return false;
		}
		if (fieldID != fieldIDEnd)
		{
			WriteLog(LogLevel::Error, "FieldID not Match. FieldID:0x%X, FieldIDEnd:0x%X", fieldID, fieldIDEnd);
			return false;
		}
		return true;
	}
	bool GetPackageStart(char* buff, int startIndex, int endIndex, int& packageStartIndex)
	{
		for (int i = startIndex; i < endIndex; ++i)
		{
			if (buff[i] == SOH && buff[i + 1] == '1' && buff[i + 2] == '=')
			{
				packageStartIndex = i;
				return true;
			}
		}
		return false;
	}

	void WriteString(char*& ppos, int key, bool value)
	{
		int len = sprintf(ppos, "%d=%d", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, char value)
	{
		int len = sprintf(ppos, "%d=%c", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, unsigned short value)
	{
		int len = sprintf(ppos, "%d=%d", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, int value)
	{
		int len = sprintf(ppos, "%d=%d", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, long long value)
	{
		int len = sprintf(ppos, "%d=%lld", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, double value)
	{
		int len = sprintf(ppos, "%d=%.6f", key, value);
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, std::string value)
	{
		int len = sprintf(ppos, "%d=%s", key, value.c_str());
		ppos += len;
		*ppos++ = SOH;
	}
	void WriteString(char*& ppos, int key, char* value)
	{
		int len = sprintf(ppos, "%d=%s", key, value);
		ppos += len;
		*ppos++ = SOH;
	}

	void WriteHexString(char*& ppos, int key, unsigned short value)
	{
		int len = sprintf(ppos, "%d=%04X", key, value);
		ppos += len;
		*ppos++ = SOH;
	}

	void HeadToStream(StepHead* head, char* buff, int size)
	{
		int len = 0;
		len += ::sprintf(buff + len, "%c%u=%04X%c", SOH, StepItems::PackageID, head->PackageID, SOH);
		len += ::sprintf(buff + len, "%u=%05u%c", StepItems::BodyLen, head->BodyLen, SOH);
		len += ::sprintf(buff + len, "%u=%d%c", StepItems::MessageChain, head->MessageChain, SOH);
		len += ::sprintf(buff + len, "%u=%13d", StepItems::MsgSeqNum, head->MsgSeqNum);
		//最后一个不能使用sprintf赋值，因为sprintf会在末尾自动补上0
		buff[len] = SOH;
	}
	bool HeadFromStream(char* buff, int startIndex, int endIndex, StepHead* head)
	{
		//跳过报文首个SOH符号
		startIndex += 1;
		unsigned short key;
		std::string value;
		int sohIndex;
		while (startIndex < endIndex)
		{
			if (GetNext(buff, startIndex,  endIndex, key, value, sohIndex))
			{
				switch (key)
				{
				case StepItems::PackageID:
					head->PackageID = stoi(value.c_str(), nullptr, 16);
					break;
				case StepItems::BodyLen:
					head->BodyLen = atoi(value.c_str());
					break;
				case StepItems::MessageChain:
					head->MessageChain = atoi(value.c_str());
					break;
				case StepItems::MsgSeqNum:
					head->MsgSeqNum = atoi(value.c_str());
					break;
				default:
					WriteLog(LogLevel::Warning, "UnExpected Key:0x%X For StepHead, buff:[%s]", key, buff);
					return false;
				}
				startIndex = sohIndex + 1;
			}
			else
			{
				break;
			}
		}
		return true;
	}
	void TailToStream(StepTail* tail, char* buff, int size)
	{
		sprintf(buff, "%u=%03u%c", StepItems::CheckSum, tail->CheckSum, SOH);
	}
	bool TailFromStream(char* buff, int startIndex, int endIndex, StepTail* tail)
	{
		while (startIndex < endIndex)
		{
			unsigned short key;
			string value;
			int sohIndex;
			if (GetNext(buff, startIndex, endIndex, key, value, sohIndex))
			{
				switch (key)
				{
				case StepItems::CheckSum:
					tail->CheckSum = atoi(value.c_str());
					break;
				default:
					WriteLog(LogLevel::Warning, "UnExpected Key:0x%X", key);
					return false;
				}
				startIndex = sohIndex + 1;
			}
			else
			{
				break;
			}
		}
		return true;
	}
	short CalculateSum(unsigned char* buff, int startIndex, int endIndex)
	{
		int sum = 0;
		for (auto i = startIndex; i < endIndex; ++i)
		{
			sum += buff[i];
		}
		return sum % 256;
	}
}
