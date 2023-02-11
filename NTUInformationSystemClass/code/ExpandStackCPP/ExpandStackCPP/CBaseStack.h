#pragma once
template<class T>
class CStack
{
private:
	const int m_StepSize;
	unsigned int m_Size;
	unsigned int m_RealSize;
	unsigned int m_End;
	T* m_Element;
	int pos;
public:
	CStack();
	~CStack();
	bool pushBack(T val);
	bool popBack(T& val);
	bool insert(int position, T value);
	bool remove(int position);
};

template<class T>
inline CStack<T>::CStack(): m_StepSize(5), m_End(0)
{
	m_RealSize = 5;
	m_Element = new int[m_RealSize];
}

template<class T>
inline CStack<T>::~CStack()
{
	delete[] m_Element;
}

template<class T>
inline bool CStack<T>::pushBack(T val)
{
	if (m_End == m_RealSize)
	{
		T* array;
		array = new T[m_RealSize + m_StepSize];
		memccpy(array, m_Element, sizeof(T)*)
	}
		
}

template<class T>
inline bool CStack<T>::popBack(T& val)
{
	val = m_Element[--m_End];
	return true;
}

template<class T>
inline bool CStack<T>::insert(int position, T value)
{
	return false;
}

template<class T>
inline bool CStack<T>::remove(int position)
{
	return false;
}
