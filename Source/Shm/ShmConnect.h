#pragma once
#include "Types.h"
#include "Connect.h"
#include "ShmBuffer.h"
#include "MemCacheTemplateSingleton.h"



template<unsigned SIZE>
class ShmConnect : public Connect
{
public:
	int Index;
	ShmBuffer<SIZE>* m_ShmBuffer;

	static ShmConnect* Allocate()
	{
		auto item = ::Allocate<ShmConnect<SIZE>>();
		item->m_ShmBuffer = ::Allocate<ShmBuffer<SIZE>>();
		return item;
	}
	void Free()
	{
		m_ShmBuffer->Free();
		m_ShmBuffer = nullptr;
		MemCacheTemplateSingleton<ShmConnect<SIZE>>::GetInstance().Free(this);
	}
};
