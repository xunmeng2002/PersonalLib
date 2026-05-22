#pragma once
#include <atomic>


template <typename T>
class LockFreeQueue
{
private:
    struct Node
    {
        Node() : data(nullptr), next(nullptr) {}
        Node(T* val) : data(val), next(nullptr) {}

        T* data;
        std::atomic<Node*> next;
    };
    std::atomic<Node*> m_Head;
    std::atomic<Node*> m_Tail;

public:
    LockFreeQueue()
    {
        Node* dummy = new Node();
        m_Head.store(dummy, std::memory_order_release);
        m_Tail.store(dummy, std::memory_order_release);
    }
    ~LockFreeQueue()
    {
        Node* node = m_Head.load(std::memory_order_acquire);
        Node* next = nullptr;
        while (node)
        {
            next = node->next.load(std::memory_order_acquire);
            delete node;
            node = next;
        }
    }
    LockFreeQueue(const LockFreeQueue&) = delete;
    LockFreeQueue& operator=(const LockFreeQueue&) = delete;
    void PushBack(T* data)
    {
        Node* newNode = new Node(data);
        Node* oldTail = nullptr;
        while (true)
        {
            oldTail = m_Tail.load(std::memory_order_acquire);
            Node* next = oldTail->next.load(std::memory_order_acquire);
            if (oldTail == m_Tail.load(std::memory_order_acquire))
            {
                if (next == nullptr)
                {
                    if (oldTail->next.compare_exchange_weak(next, newNode, std::memory_order_release, std::memory_order_acquire))
                    {
                        m_Tail.store(newNode, std::memory_order_release);
                        return;
                    }
                }
                else
                {
                    m_Tail.store(next, std::memory_order_release);
                }
            }
        }
    }
    T* PopFront()
    {
        Node* oldHead = nullptr;
        while (true)
        {
            oldHead = m_Head.load(std::memory_order_acquire);
            Node* tail = m_Tail.load(std::memory_order_acquire);
            Node* next = oldHead->next.load(std::memory_order_acquire);
            if (oldHead == m_Head.load(std::memory_order_acquire))
            {
                if (oldHead == tail)
                {
                    if (next == nullptr)
                    {
                        return nullptr;
                    }
                    m_Tail.store(next, std::memory_order_release);
                }
                else
                {
                    T* data = next->data;
                    if (m_Head.compare_exchange_weak(oldHead, next, std::memory_order_release, std::memory_order_acquire))
                    {
                        delete oldHead;
                        return data;
                    }
                }
            }
        }
    }
    bool Empty() const
    {
        return m_Head.load(std::memory_order_acquire) == m_Tail.load(std::memory_order_acquire);
    }
};

