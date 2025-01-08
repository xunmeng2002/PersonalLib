#pragma once
#include "Types.h"

class DBOperate
{
public:
	static DBOperate* Allocate();
	virtual void Free() = 0;
	virtual void FreeRecord() = 0;
	virtual const char* GetDebugString() const = 0;


	DBOperateType Operate;
	unsigned int TableID;
	unsigned int IndexID;
	void* Record;
};
