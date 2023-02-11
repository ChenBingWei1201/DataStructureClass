#pragma once
#include <iostream>
template<class T>
class CNode
{
public:
	CNode();
	~CNode() {};
	T m_Value;
	CNode<T>* m_Next;
	CNode<T>* m_Last;
};

template<class T>
inline CNode<T>::CNode()
	: m_Value()
	, m_Next(NULL)
	, m_Last(NULL)
{
}
