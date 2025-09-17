#pragma once
#include "MemCacheTemplateSingleton.h"
#include "Constant.h"
#include <string.h>

template<unsigned SIZE>
class Buffer
{
public:
	Buffer()
		:m_Buffer{0}, m_Length(0), m_ReadPos(m_Buffer)
	{}
	static Buffer* Allocate()
	{
		return ::Allocate<Buffer<SIZE>>();
	}
	void Free()
	{
		Reset();
		MemCacheTemplateSingleton<Buffer<SIZE>>::GetInstance().Free(this);
	}
	unsigned Append(const char* data, unsigned len)
	{
		auto size = GetWriteBufferSize();
		len = len > size ? size : len;
		std::memcpy(m_ReadPos + m_Length, data, len);
		m_Length += len;
		return len;
	}
	char* GetData()
	{
		return m_ReadPos;
	}
	char* GetWritePos()
	{
		return m_ReadPos + m_Length;
	}
	void SetLength(unsigned len)
	{
		m_Length = len;
	}
	unsigned GetLength()
	{
		return m_Length;
	}

	unsigned GetWriteBufferSize()
	{
		return unsigned((m_Buffer + SIZE) - (m_ReadPos + m_Length));
	}
	void Shift(unsigned len)
	{
		m_ReadPos += len;
		m_Length -= len;
	}
	void Reset()
	{
		memset(m_Buffer, 0, SIZE);
		m_ReadPos = m_Buffer;
		m_Length = 0;
	}
	void MemMove()
	{
		if (m_Length == 0)
			return;
		memmove(m_Buffer, m_ReadPos, m_Length);
		m_ReadPos = m_Buffer;
	}

private:
	char m_Buffer[SIZE];
	unsigned m_Length;
	char* m_ReadPos;
};
