#pragma once
template<class T>
class CStack
{
private:
	const int m_StepSize;		// the unit of expand of lenght of an array
	unsigned int m_RealSize;	// the lenght of the original array
	int m_End, end;				// the address of the last element without values
	T* m_Array;					// the array for storing values
	int pos;					// decord the address of the array whrere user want to alter
public:
	CStack();
	~CStack();
	bool push(T val); 
	bool pop(T& val);
	bool insert(int position, T value);
	bool remove(int position);
};

template<class T>
inline CStack<T>::CStack() : m_StepSize(5), m_End(0), pos(0), end(0)
{
	m_RealSize = 5;
	m_Array = new T[m_RealSize];
}

template<class T>
inline CStack<T>::~CStack()
{
	delete[] m_Array;
}

template<class T>
inline bool CStack<T>::push(T val)
{
	if (m_End == m_RealSize)
	{
		T* array;
		array = new T[m_RealSize + m_StepSize]; 
		memcpy(array, m_Array, sizeof(T) * m_RealSize);
		m_Array = array; // 離開會自動消失，把他所指的地方delete掉!
		m_Array[m_End] = val;
		m_End++;
		m_RealSize += m_StepSize; 
	}
	else
	{
		m_Array[m_End] = val;
		m_End++;
	}
	end = m_End; 
	return true;
}

template<class T>
inline bool CStack<T>::pop(T& val)
{
	if (m_End > 0)
	{
		m_End--; 
		val = m_Array[m_End];
		return true;
	}
	else
		return false;
}

template<class T>
inline bool CStack<T>::insert(int position, T value)
{
	m_End = end;
	if (m_End == m_RealSize) // 全滿
	{
		pos = position;
		T* array;
		array = new T[m_RealSize + m_StepSize];
		memcpy(array, m_Array, sizeof(T) * m_RealSize);
		m_Array = array;
		m_RealSize += m_StepSize;

		for (int i = m_End - 1; i >= pos; i--)
			m_Array[i + 1] = m_Array[i];

		m_Array[pos] = value;
		m_End++;
		end++;
	}
	else
	{
		pos = position;
		for (int i = m_End - 1; i >= pos; i--)
			m_Array[i + 1] = m_Array[i];

		m_Array[pos] = value;
		m_End++;
		end++;
	}
	return true;
}

template<class T>
inline bool CStack<T>::remove(int position)
{
	m_End = end;
	if (m_End == 0) // 全空
		return false;
	else
	{
		pos = position; 
		for (int i = pos; i < m_End - 1; i++) 
			m_Array[i] = m_Array[i + 1];
		m_End--;
	}
	end--;
	return true;
}