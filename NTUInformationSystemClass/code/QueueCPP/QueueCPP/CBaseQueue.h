#pragma once
template<class T>
class BaseQueue
{
public:
	BaseQueue();
	~BaseQueue();
	bool setSize(int size);
	bool push(T value);
	bool pop(T& value);
	bool insert(int pos, T value);
	bool remove(int pos);
private:
	int head, end, originEnd;
	int elementNumber, m_Size;
	int position = 0;
	T* qArray;
};

template<class T>
inline BaseQueue<T>::BaseQueue() : 
	head(0), end(0), elementNumber(0), m_Size(0), qArray(NULL)
{
}

template<class T>
inline BaseQueue<T>::~BaseQueue()
{
	delete[] qArray;
}

template<class T>
inline bool BaseQueue<T>::setSize(int size)
{
	if (qArray)
		delete[] qArray;
	qArray = new T[size];
	if (!qArray)
		return false;
	m_Size = size;
}

template<class T>
inline bool BaseQueue<T>::push(T value)
{
	if (end + 1 > m_Size)
		return false;
	else
		qArray[end++] = value;
	elementNumber++;
	
	return true;
}

template<class T>
inline bool BaseQueue<T>::pop(T& value)
{
	if (end == 0)
		return false;
	else
		value = qArray[head++];
	elementNumber--;
	return true;
}

template<class T>
inline bool BaseQueue<T>::insert(int pos, T value)
{
	if (end + 1 > m_Size)
		return false;
	else
	{
		position = pos;
		for (int i = pos; i < end; i++)
			qArray[i + 1] = qArray[i];
		qArray[pos] = value;
	}
	return true;
}

template<class T>
inline bool BaseQueue<T>::remove(int pos)
{
	return false;
}
