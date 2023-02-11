#pragma once
#include "CNode.h"
template<class T>
class CDoubleLinkedList
{
public:
	CDoubleLinkedList();
	~CDoubleLinkedList();
	void Show();
	bool AddBack(T val);
	bool AddFront(T val);
	bool Insert(int pos, T val);
	bool Remove(int pos, T val);
private:
	CDoubleLinkedList<T>* m_Head;
	CDoubleLinkedList<T>* m_Tail;
};

template<class T>
inline CDoubleLinkedList<T>::CDoubleLinkedList()
	: m_Head(NULL)
	, m_Tail(NULL)
{
}

template<class T>
inline CDoubleLinkedList<T>::~CDoubleLinkedList()
{
}

template<class T>
inline void CDoubleLinkedList<T>::Show()
{
	CNode<T>* now = m_Head;
	while (now)
	{
		std::cout << now->m_Value << ", ";
		now = now->m_Value;
	}
	std::cout << "\n";
}

template<class T>
inline bool CDoubleLinkedList<T>::AddBack(T val)
{
	if (!m_Tail && !m_Tail)
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;

	}
	return false;
}

template<class T>
inline bool CDoubleLinkedList<T>::AddFront(T val)
{
	return false;
}

template<class T>
inline bool CDoubleLinkedList<T>::Insert(int pos, T val)
{
	return false;
}

template<class T>
inline bool CDoubleLinkedList<T>::Remove(int pos, T val)
{
	return false;
}
