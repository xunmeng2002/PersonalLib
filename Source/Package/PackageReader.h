#pragma once
#include "Package.h"


class PackageReader
{
public:
	PackageReader();
	~PackageReader();
	void Reset();
	void PopFront(unsigned int len);
	char* Data();
	int Length();
	char* Tail();
	unsigned int TailSize();
	void Shift(unsigned int len);
	unsigned int Append(char* data, unsigned  int len);

protected:
	char m_Buff[MaxPackageSize * 2];
	char* m_Data;
	unsigned int m_Length;
};

