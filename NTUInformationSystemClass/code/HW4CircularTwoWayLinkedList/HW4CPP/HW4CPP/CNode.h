#pragma once
template<class T>
class CNode
{
public:
	CNode();
	~CNode() {};
	T m_Value;
	CNode<T>* m_Next; // the next one(�U�@��)
	CNode<T>* m_Last; // the last one(�W�@��)
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
