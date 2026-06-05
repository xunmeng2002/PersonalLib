#pragma once
#include <string>
#include <unordered_map>
#include "PersonalLib/Types.h"
#include "PersonalLib/Network/Protocol/Head.h"


constexpr unsigned int StepHeaderLen = 36u;
constexpr unsigned int StepTailLen = 9u;
constexpr unsigned int SOH = 1u;


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


void HeadToStream(HeadField* head, char* buff, int size);
bool HeadFromStream(char* buff, int startIndex, int endIndex, HeadField* head);
void TailToStream(TailField* tail, char* buff, int size);
bool TailFromStream(char* buff, int startIndex, int endIndex, TailField* tail);
