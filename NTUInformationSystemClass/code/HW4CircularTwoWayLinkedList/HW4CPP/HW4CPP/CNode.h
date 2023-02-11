#pragma once
template<class T>
class CNode
{
public:
	CNode();
	~CNode() {};
	T m_Value;
	CNode<T>* m_Next; // the next one(下一個)
	CNode<T>* m_Last; // the last one(上一個)
	bool isEmpty; // the node is empty or not
};

template<class T>
inline CNode<T>::CNode() 
	: m_Value()
	, m_Next(NULL)
	, m_Last(NULL)
	, isEmpty(true)
{
}
