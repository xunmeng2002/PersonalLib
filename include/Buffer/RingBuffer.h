#pragma once
#include "MemCache/MemCacheTemplateSingleton.h"
#include "Constant/Constant.h"
#include <string.h>

template<unsigned SIZE>
class RingBuffer
{
public:
	RingBuffer()
		:m_Buffer{ 0 }, m_ReadPos(m_Buffer), m_WritePos(m_Buffer)
	{}
	static RingBuffer* Allocate()
	{
		return ::Allocate<RingBuffer<SIZE>>();
	}
	void Free()
	{
		Reset();
		MemCacheTemplateSingleton<RingBuffer<SIZE>>::GetInstance().Free(this);
	}
	unsigned Append(const char* data, unsigned len)
	{
		auto size = GetWriteBufferSize();
		len = std::min(len, size);
		unsigned tailLen = (m_Buffer + SIZE) - m_WritePos;
		tailLen = std::min(tailLen, len);
		memcpy(m_WritePos, data, tailLen);
		if (tailLen < len)
		{
			memcpy(m_Buffer, data + tailLen, size_t(len - tailLen));
			m_WritePos = m_Buffer + len - tailLen;
		}
		else
		{
			m_WritePos = m_WritePos + tailLen;
		}
		return len;
	}
	char* GetReadPos()
	{
		return m_ReadPos;
	}
	void ShiftRead(unsigned len)
	{
		if (m_ReadPos + len < m_Buffer + SIZE)
		{
			m_ReadPos = m_ReadPos + len;
		}
		else
		{
			m_ReadPos = m_ReadPos + len - SIZE;
		}
	}
	char* GetWritePos()
	{
		return m_WritePos;
	}
	void ShiftWrite(unsigned len)
	{
		if (m_WritePos + len < m_Buffer + SIZE)
		{
			m_WritePos = m_WritePos + len;
		}
		else
		{
			m_WritePos = m_WritePos + len - SIZE;
		}
	}
	unsigned GetReadBufferSize()
	{
		if (m_ReadPos < m_WritePos)
		{
			return m_WritePos - m_ReadPos;
		}
		return SIZE - (m_ReadPos - m_WritePos);
	}
	unsigned GetWriteBufferSize()
	{
		if (m_WritePos < m_ReadPos)
		{
			return m_ReadPos - m_WritePos - 1;
		}
		return SIZE - (m_WritePos - m_ReadPos) - 1;
	}

	void Reset()
	{
		memset(m_Buffer, 0, SIZE);
		m_ReadPos = m_Buffer;
		m_WritePos = m_Buffer;
	}

private:
	char* m_ReadPos;
	char* m_WritePos;
	char m_Buffer[SIZE];
};
