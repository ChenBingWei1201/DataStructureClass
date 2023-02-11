#pragma once
template<class T>
class CNode
{
public:
	CNode();
	~CNode();
	CNode<T>* m_Left;
	CNode<T>* m_Right;
	T m_Value;
	bool m_IsEmpty;
};

template<class T>
inline CNode<T>::CNode()
	: m_Left(NULL)
	, m_Right(NULL)
	, m_IsEmpty(true)
	, m_Value()
{
}

template<class T>
inline CNode<T>::~CNode()
{
}
