#pragma once
#include <iostream>
#include "CNode.h"
template<class T>
class CLinkedList
{
public:
	CLinkedList();
	~CLinkedList();
	void Show();
	bool Insert(int pos, T val);
	bool AddFront(T val);
	bool AddBack(T val);
	bool Remove(int pos);
private:
	CNode<T>* m_Head;
};

template<class T>
inline CLinkedList<T>::CLinkedList() : m_Head(NULL)
{
}

template<class T>
inline CLinkedList<T>::~CLinkedList()
{
}

template<class T>
inline void CLinkedList<T>::Show()
{
	CNode<T>* now = m_Head;
	if (now)
	{
		std::cout << now -> m_Value << ", ";
		now = now -> m_Next;
	}
	std::cout << "\n";
}

template<class T>
inline bool CLinkedList<T>::Insert(int pos, T val)
{
	if (pos == 0)
		return AddFront(val);

	if (!m_Head)
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;
		m_Head->m_Value = val;
	}
	else
	{
		CNode<T>* now = m_Head;
		for (int i = 0; i < pos - 1; i++)
			if (now->m_Next)
				now = now->m_Next;
		CNode<T>* insertItem = new CNode<T>;
		if (!insertItem)
			return true;
		insertItem->m_Value = val;
		insertItem->m_Next = now->m_Next;
		now->m_Next = insertItem;
	}
	return true;
}

template<class T>
inline bool CLinkedList<T>::AddFront(T val)
{
	if (!m_Head)
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;
		m_Head->m_Value = val;
	}
	else
	{
		CNode<T>* now = new CNode<T>;
		if (!now)
			return false;
		now->m_Next = m_Head;
		m_Head = now;
		now->m_Value = val;
	}

	return false;
}

template<class T>
inline bool CLinkedList<T>::AddBack(T val)
{
	if (!m_Head)
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;
		m_Head->m_Value = val;
	}
	else
	{
		CNode<T> now = m_Head;
		while (now->m_Next)
			now = now->m_Next;
		now->m_Next = new CNode<T>;
		now = now->m_Next;
		now->m_Value = val;
	}
	return true;
}

template<class T>
inline bool CLinkedList<T>::Remove(int pos)
{
	if (m_Head == NULL)
		return false;
	
	CNode<T>* now = m_Head;
	CNode<T>* deleteItem;
	if (pos == 0)
	{
		deleteItem = m_Head;
		m_Head = m_Head->m_Next;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			if (now->m_Next == NULL)
				return false;
			now = now->m_Next;
		}
		if (now->m_Next == NULL)
			return false;
		deleteItem = now->m_Next;
		now->m_Next = now->m_Next->m_Next;
	}
	delete deleteItem;
	return true;
}
