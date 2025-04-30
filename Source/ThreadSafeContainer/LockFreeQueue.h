#pragma once
#include <atomic>


template <typename T>
class LockFreeQueue
{
private:
	struct Node
	{
		Node()
			:data(nullptr), next(nullptr)
		{ }
		T* data;
		Node* next;
	};
public:
	LockFreeQueue()
		:m_Head(new Node), m_Tail(m_Head.load())
	{}
	LockFreeQueue(const LockFreeQueue&) = delete;
	LockFreeQueue& operator(const LockFreeQueue&) = delete;
	~LockFreeQueue()
	{
		Node* oldHead = nullptr;
		while (oldHead = m_Head.load())
		{
			m_Head.store(oldHead->next);
			delete oldHead->data;
			delete oldHead;
		}
	}

	T* PopFront()
	{
		auto oldHead = m_Head.load();
		if (oldHead == m_Tail.load())
		{
			return nullptr;
		}
		m_Head.store(oldHead->next);
		auto data = oldHead->data;
		delete oldHead;
		return data;
	}
	void PushBack(T* data)
	{
		Node* node = new Node();
		auto oldTail = m_Tail.load();
		oldTail->data = data;
		oldTail->next = node;
		m_Tail.store(node);
	}
	bool Empty()
	{
		return m_Head.load() == m_Tail.load();
	}

private:
	std::atomic<Node*> m_Head;
	std::atomic<Node*> m_Tail;
};

