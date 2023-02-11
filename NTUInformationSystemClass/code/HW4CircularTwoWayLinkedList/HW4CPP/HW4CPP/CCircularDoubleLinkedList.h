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
	CNode<T>* m_Head; // �Ĥ@�Ӧ��Ȫ�node
	CNode<T>* m_Tail; // �̫�@��node
	int elementNum; // ���Ȫ�node���ƶq
	int capacity; // �e�q(node��)�Auser�@�}�l���w�A���i�W�L
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
		m_Head->m_Last = NULL; // ���q�}��������A�Ѻc
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
	capacity = size; // user����size�Ƕi��assign��capacity
	if (capacity == 1) // �u�}�@��node
	{
		m_Head = new CNode<T>;
		if (!m_Head)
			return false;
		m_Head->isEmpty = true; // �̪�@�}�l�S����
		m_Tail = m_Head; // �]���u���@��node
		m_Head->m_Last = NULL;
		m_Head->m_Next = NULL;
	}
	else // �}�ܤ֨��node
	{ 
		for (int i = 0; i < capacity; i++)
		{
			if (i == 0) // head (the first node)
			{
				m_Head = new CNode<T>;
				if (!m_Head)
					return false;
				m_Head->isEmpty = true; // �̪�@�}�l�S����
				m_Tail = m_Head; // �]���u���@��node
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
			if (now->isEmpty) // �J��Ū�node�Nbreak��
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
	if (!m_Tail && !m_Head) // �S������node�s�b
		return false;
	else if (elementNum == capacity) // �����F(�S���Ū�node�F)
		return false;
	else // ����node
	{
		elementNum++;
		CNode<T>* now = m_Head; // �qm_Head�}�l
		for (int i = 0; i < capacity; i++) // ����
		{
			if (now->isEmpty) // ���ߨ��node
			{
				now->m_Value = val; // ���
				now->isEmpty = false; // ���F��F
				break; // ���Xloop
			}
			now = now->m_Next; // �Y���O��node�A�X�ݤU�@��node
		}
	}
	return true; // ���\!
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::AddFront(T val) // finish
{
	if (!m_Tail && !m_Head) // �S������node�s�b
		return false;
	else if (elementNum == capacity) // �����F(�S���Ū�node�F)
		return false;
	else
	{
		elementNum++;
		CNode<T>* now = m_Head; // �qm_Head�}�l
		for (int i = 0; i < capacity; i++) // ����
		{
			if (now->isEmpty) // ���ߨ��node
			{
				now->m_Value = val; // ���
				now->isEmpty = false;
				break; // ���Xloop
			}
			now = now->m_Last; // �Y���O��node�A�X�ݤW�@��node
		}
		m_Head = now; // ��m_Tail?
		m_Tail = m_Head->m_Last; // key
	}
	return true;// ���\!
}

template<class T>
inline bool CCircularDoubleLinkedList<T>::Insert(int pos, T val) // finish
{
	if (!m_Tail && !m_Head) // �L����node�A�S���a��i�Hinsert
		return false;
	else if (pos >= capacity) // �Q���J����m�h�l�e�q
		return false;
	else if (pos >= elementNum)
		return AddBack(val);
	else if (elementNum == capacity)
		return false;
	else
	{
		CNode<T>* now = m_Head; // ���qm_Head�}�l���U��
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
	if (!m_Tail && !m_Head) // �L����node�A�S���a��i�Hremove
		return false;
	else if (pos >= capacity)
		return false;
	else if (pos >= elementNum)
		return false;
	else if (pos == 0) // �R���Y
	{
		deleteItem = m_Head;
		m_Head = m_Head->m_Next;
		deleteItem->m_Last->m_Next = m_Head;
		deleteItem->m_Next->m_Last = deleteItem->m_Last;
	}
	else if (pos == capacity - 1) // �R����
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
