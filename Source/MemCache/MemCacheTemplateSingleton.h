#pragma once
#include <list>
#include <mutex>
#include <cstring>


template <typename T>
class MemCacheTemplateSingleton
{
private:
	MemCacheTemplateSingleton()
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

	T* Allocate(int blockUnitNum = 64)
	{
		std::lock_guard<std::mutex> guard(m_Mutex);
		if (m_Items.empty())
		{
			AllocateBlock(blockUnitNum);
		}
		auto item = m_Items.front();
		m_Items.pop_front();
		return item;
	}
	void Free(T* item)
	{
		std::lock_guard<std::mutex> guard(m_Mutex);
		m_Items.push_back(item);
	}

private:
	void AllocateBlock(int blockUnitNum)
	{
		char* newBlock = new char[sizeof(T) * blockUnitNum];
		for (auto i = 0; i < blockUnitNum; ++i)
		{
			m_Items.push_back(new(newBlock + i * sizeof(T)) T());
			//m_Items.push_back(reinterpret_cast<T*>(newBlock + i * sizeof(T)));
		}
		m_Pools.push_back(newBlock);
	}

private:
	static MemCacheTemplateSingleton m_Instance;
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
	MemCacheTemplateSingleton<T>::GetInstance().Free(item);
}

