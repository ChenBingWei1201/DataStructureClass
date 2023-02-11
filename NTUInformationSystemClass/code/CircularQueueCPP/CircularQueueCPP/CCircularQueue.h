#pragma once
template<class T>
class CCircularQueue
{
private:
	int elementNum, capacity;
	int head, tail, position;
	T* qArray;
public:
	CCircularQueue();
	~CCircularQueue();
	bool setSize(int size);
	bool push(T value);
	bool pop(T& value);
	
};

template<class T>
inline CCircularQueue<T>::CCircularQueue()
	: elementNum(0)
	, capacity(0)
	, head(0)
	, tail(0)
	, position(0)
{
}

template<class T>
inline CCircularQueue<T>::~CCircularQueue()
{
	delete[] qArray;
}

template<class T>
inline bool CCircularQueue<T>::setSize(int size)
{
	if (qArray)
		delete[] qArray;
	qArray = new T[size];
	if (!qArray)
		return false;
	capacity = size;
	return true;
}

template<class T>
inline bool CCircularQueue<T>::push(T value)
{
	if (elementNum == capacity)
		return false;

	if (tail + 1 > capacity)
	{
		tail = 0;
		qArray[tail++] = value;
	}
	else
		qArray[tail++] = value;
	elementNum++;
	return true;
}

template<class T>
inline bool CCircularQueue<T>::pop(T& value)
{
	if (tail == 0)
		return false;
	if (head + 1 > capacity)
	{
		head = 0;
		qArray[head++] = value;
	}
	else
		value = qArray[head++];
	elementNum--;
	return true;
}
