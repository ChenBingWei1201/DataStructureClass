#pragma once
#include <iostream>
#include "CNode.h"
template<class T>
class CCircularDoubleLinkedList
{
public:
	CCircularDoubleLinkedList();
	~CCircularDoubleLinkedList();
	bool SetSize(int size);
	void Show();
	bool AddBack(T val);
	bool AddFront(T val);
	bool Insert(int pos, T val);
	bool Remove(int pos);
private:
	bool AddNode();
	bool DeleteNode();
	CNode<T>* m_Head; // 第一個有值的node
	CNode<T>* m_Tail; // 最後一個node
	int elementNum; // 有值的node的數量
	int capacity; // 容量(node數)，user一開始給定，不可超過
};

template<class T>
inline CCircularDoubleLinkedList<T>::CCircularDoubleLinkedList() // finsish
	: m_Head(NULL)
	, m_Tail(NULL)
	, elementNum(0)
	, capacity(0)
{
}

template<class T>
inline CCircularDoubleLinkedList<T>::~CCircularDoubleLinkedList() // finsish
{
	if (capacity == 1)
		delete m_Head;
	else
	{
		m_Head->m_Last = NULL; // 先段開環成直鏈再解構
		m_Tail->m_Next = NULL;
		CNode<T>* now = m_Head;
		while (now)
		{
			CNode<T>* next = now->m_Next;
			delete now;
			now = next;
		}
	}
	
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::SetSize(int size) // finsish
{
	capacity = size; // user給的size傳進來assign給capacity
	if (capacity == 1) // 只開一個node
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;
		m_Head->isEmpty = true; // 最初一開始沒給值
		m_Tail = m_Head; // 因為只有一個node
		m_Head->m_Last = NULL;
		m_Head->m_Next = NULL;
	}
	else // 開至少兩個node
	{ 
		for (int i = 0; i < capacity; i++)
		{
			if (i == 0) // head (the first node)
			{
				m_Head = new CNode<T>;
				if (!m_Head)
					return false;
				m_Head->isEmpty = true; // 最初一開始沒給值
				m_Tail = m_Head; // 因為只有一個node
				m_Head->m_Last = NULL;
				m_Head->m_Next = NULL;
			}
			else // other nodes
			{
				m_Tail->m_Next = new CNode<T>;
				if (!m_Tail->m_Next)
					return false;
				m_Tail->m_Next->m_Last = m_Tail;
				m_Tail = m_Tail->m_Next;
				m_Tail->m_Next = NULL;
				m_Tail->isEmpty = true;
				if (i == capacity - 1)
				{
					m_Tail->m_Next = m_Head;
					m_Head->m_Last = m_Tail;
				}
			}
		}
	}
	return true;
}

template<class T>
inline void CCircularDoubleLinkedList<T>::Show() // finish
{
	CNode<T>* now = m_Head;
	std::cout << "the values in the linked list now:\n";
	if (m_Head != m_Tail) // more than one element in the linked list
	{
		// std::cout << "\n" << elementNum << "\n";
		for (int i = 0; i < elementNum; i++)
		{
			if (now->isEmpty) // 遇到空的node就break掉
				break;
			else 
				std::cout << now->m_Value << ", ";
			now = now->m_Next;
		}
	}
	else
		std::cout << now->m_Value << ", ";

	std::cout << "\n\n";
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::AddBack(T val) // finish
{
	if (!m_Tail && !m_Head) // 沒有任何node存在
		return false;
	else if (elementNum == capacity) // 全滿了(沒有空的node了)
		return false;
	else // 有空node
	{
		elementNum++;
		CNode<T>* now = m_Head; // 從m_Head開始
		for (int i = 0; i < capacity; i++) // 輪詢
		{
			if (now->isEmpty) // 輪詢到空node
			{
				now->m_Value = val; // 放值
				now->isEmpty = false; // 有東西了
				break; // 跳出loop
			}
			now = now->m_Next; // 若不是空node，訪問下一個node
		}
	}
	return true; // 成功!
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::AddFront(T val) // finish
{
	if (!m_Tail && !m_Head) // 沒有任何node存在
		return false;
	else if (elementNum == capacity) // 全滿了(沒有空的node了)
		return false;
	else
	{
		elementNum++;
		CNode<T>* now = m_Head; // 從m_Head開始
		for (int i = 0; i < capacity; i++) // 輪詢
		{
			if (now->isEmpty) // 輪詢到空node
			{
				now->m_Value = val; // 放值
				now->isEmpty = false;
				break; // 跳出loop
			}
			now = now->m_Last; // 若不是空node，訪問上一個node
		}
		m_Head = now; // 那m_Tail?
		m_Tail = m_Head->m_Last; // key
	}
	return true;// 成功!
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::Insert(int pos, T val) // finish
{
	if (!m_Tail && !m_Head) // 無任何node，沒有地方可以insert
		return false;
	else if (pos >= capacity) // 想插入的位置多餘容量
		return false;
	else if (pos >= elementNum)
		return AddBack(val);
	else if (elementNum == capacity)
		return false;
	else
	{
		CNode<T>* now = m_Head; // 先從m_Head開始往下走
		for (int i = 0; i < pos - 1; i++) // pos = 3
			now = now->m_Next; 
			
		CNode<T>* insertItem = new CNode<T>;
		if (!insertItem) // fail to new insertItem
			return false;
		insertItem->m_Value = val;
		insertItem->isEmpty = false;
		insertItem->m_Last = now;
		insertItem->m_Next = now->m_Next;
		now->m_Next = insertItem;
		insertItem->m_Last->m_Next = insertItem;
		if (insertItem->m_Next)
			insertItem->m_Next->m_Last = insertItem;
		elementNum++;
	}	
	return DeleteNode();
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::Remove(int pos) // finish
{
	CNode<T>* now = m_Head;
	CNode<T>* deleteItem;
	if (!m_Tail && !m_Head) // 無任何node，沒有地方可以remove
		return false;
	else if (pos >= capacity)
		return false;
	else if (pos >= elementNum)
		return false;
	else if (pos == 0) // 刪掉頭
	{
		deleteItem = m_Head;
		m_Head = m_Head->m_Next;
		deleteItem->m_Last->m_Next = m_Head;
		deleteItem->m_Next->m_Last = deleteItem->m_Last;
	}
	else if (pos == capacity - 1) // 刪掉尾
	{
		deleteItem = m_Tail;
		m_Tail = m_Tail->m_Last;
		deleteItem->m_Last->m_Next = m_Head;
		deleteItem->m_Next->m_Last = deleteItem->m_Last;
	}
	else
	{
		for (int i = 0; i < pos; i++)
			if (now->m_Next)
				now = now->m_Next;
		
		deleteItem = now;
		deleteItem->m_Last->m_Next = deleteItem->m_Next;
		if (deleteItem->m_Next)
			deleteItem->m_Next->m_Last = deleteItem->m_Last;
	}
	delete deleteItem;
	elementNum--;
	return AddNode();
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::AddNode()
{
	CNode<T>* addItem = new CNode<T>;
	if (!addItem) // fail to new addItem
		return false;
	addItem->isEmpty = true;
	addItem->m_Next = m_Tail->m_Next;
	addItem->m_Last = m_Tail;
	addItem->m_Last->m_Next = addItem;
	addItem->m_Next->m_Last = addItem;
	m_Tail = addItem;
	return true;
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::DeleteNode() // finish
{
	CNode<T>* deleteItem = m_Tail;
	m_Tail = m_Tail->m_Last;
	if (!deleteItem)
		return false;
	m_Tail->m_Next = m_Head;
	m_Head->m_Last = m_Tail;
	delete deleteItem;
	return true;
}
