#pragma once
template<class T>
class CNode
{
public:
	CNode();
	~CNode();
	T m_Value;
	CNode<T>* m_Next;
};

template<class T>
inline CNode<T>::CNode(): m_Value(), m_Next(NULL)
{
}

template<class T>
inline CNode<T>::~CNode()
{
}
