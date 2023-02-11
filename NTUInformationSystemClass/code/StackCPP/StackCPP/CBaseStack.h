#pragma once
template<class T>
class CStack
{
private:
	unsigned int m_Size;
	unsigned int m_End;
	T* m_Element;
	int pos;
public:
	CStack();
	~CStack();
	bool setSize(int size);
	bool push(T val);
	bool pop(T& val);
	bool insert(int position, T value);
	bool remove(int position);
};

template<class T>
inline CStack<T>::CStack(): m_Size(0), m_End(0), m_Element(NULL), pos(0)
{
}

template<class T>
inline CStack<T>::~CStack()
{
	delete[] m_Element;
}

template<class T>
inline bool CStack<T>::setSize(int size)
{
	if (m_Element)
		delete[]m_Element;
	m_Element = new T[size];
	if (!m_Element)
		return false;
	m_Size = size;
	return true;
}

template<class T>
inline bool CStack<T>::push(T val)
{
	m_Element[m_End++] = val;
	return true;
}

template<class T>
inline bool CStack<T>::pop(T& val)
{
	val = m_Element[--m_End];
	return true;
}

template<class T>
inline bool CStack<T>::insert(int position, T value)
{
	pos = position;
	for (int i = m_End - 1; i >= pos; i--)
		m_Element[i + 1] = m_Element[i];
	m_Element[pos] = value;
	m_End++;
	return true;
}

template<class T>
inline bool CStack<T>::remove(int position)
{
	pos = position; // pos = 1, m_End = 3
	for (int i = pos; i < m_End; i++) // 1 
		m_Element[i] = m_Element[i + 1];
	m_End--;
	return true;
}
