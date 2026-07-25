#pragma once
#include <list>
#include <mutex>
#include <cstring>
#include <stdlib.h>


template <typename T>
class MemCacheTemplateSingleton
{
private:
	MemCacheTemplateSingleton()
		:m_BlockUnitNum(64)
	{
	}
	~MemCacheTemplateSingleton()
	{
		std::lock_guard<std::mutex> guard(m_Mutex);
		for (auto& pool : m_Pools)
		{
			delete[] pool;
		}
		m_Pools.clear();
		m_Items.clear();
	}
	MemCacheTemplateSingleton(MemCacheTemplateSingleton&) = delete;
	MemCacheTemplateSingleton& operator=(MemCacheTemplateSingleton&) = delete;
public:
	static MemCacheTemplateSingleton& GetInstance()
	{
		return m_Instance;
	}
	void SetBlockUnitNum(int blockUnitNum)
	{
		m_BlockUnitNum = blockUnitNum;
	}

	T* Allocate()
	{
		std::lock_guard<std::mutex> guard(m_Mutex);
		if (m_Items.empty())
		{
			AllocateBlock();
		}
		auto item = m_Items.front();
		m_Items.pop_front();
		return item;
	}
	void Free(T* item)
	{
		if (item == nullptr)
			return;
		std::lock_guard<std::mutex> guard(m_Mutex);
		m_Items.push_back(item);
	}

private:
	void AllocateBlock()
	{
		char* newBlock = (char*)malloc(sizeof(T) * m_BlockUnitNum);
		for (auto i = 0; i < m_BlockUnitNum; ++i)
		{
			m_Items.push_back(new(newBlock + i * sizeof(T)) T());
		}
		m_Pools.push_back(newBlock);
	}

private:
	static MemCacheTemplateSingleton m_Instance;
	int m_BlockUnitNum;
	std::list<T*> m_Items;
	std::mutex m_Mutex;
	std::list<char*> m_Pools;
};

template<typename T>
MemCacheTemplateSingleton<T> MemCacheTemplateSingleton<T>::m_Instance;


template<typename T>
T* Allocate()
{
	return MemCacheTemplateSingleton<T>::GetInstance().Allocate();
}
template<typename T>
void Free(T* item)
{
	memset(item, 0, sizeof(T));
	MemCacheTemplateSingleton<T>::GetInstance().Free(item);
}

