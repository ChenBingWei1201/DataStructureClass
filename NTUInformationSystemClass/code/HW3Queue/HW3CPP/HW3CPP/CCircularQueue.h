#pragma once
enum type {PushBack = 1, PushFront, PopBack, PopFront};
template<class T>
class CCircularQueue
{
private:
	int elementNum; // the number of the elements in the array
	int capacity;   // the capacity of the array
	int head;		// the index of the first element whose value have given
	int tail;		// the index of the first void space whose value haven't given
	T* qArray;		// the array to store element
public:
	CCircularQueue();
	~CCircularQueue();
	bool setSize(int size);
	bool pushBack(T value); // oringinal push
	bool pushFront(T val); 
	bool popBack(T& val);
	bool popFront(T& val);  // original pop
};

template<class T>
inline CCircularQueue<T>::CCircularQueue()
	: elementNum(0)
	, capacity(0)
	, head(0)
	, tail(0)
	, qArray(NULL)
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
inline bool CCircularQueue<T>::pushBack(T value) // 屁股入
{
	if (elementNum == capacity) // full
		return false;

	if (tail == capacity)
	{
		tail = 0; // circular
		qArray[tail++] = value;
	}
	else
		qArray[tail++] = value;
	elementNum++;
	return true;
}

template<class T>
inline bool CCircularQueue<T>::pushFront(T val) // 嘴巴入
{
	if (elementNum == capacity)
		return false;

	if (head == 0)
	{
		head = capacity - 1;
		qArray[head] = val;
	}
	else
		qArray[--head] = val;
	elementNum++;
	return true;
}

template<class T>
inline bool CCircularQueue<T>::popBack(T& val) // 屁股出
{
	if (elementNum == 0)
		return false;
	if (tail == 0)
	{
		tail = capacity;
		val = qArray[--tail];
	}
	else
		val = qArray[--tail];
	elementNum--;
	return true;
}

template<class T>
inline bool CCircularQueue<T>::popFront(T& value) // 嘴巴出
{
	if (elementNum == 0) // none
		return false;

	if (head == capacity)
	{
		head = 0;
		value = qArray[head++];
	}
	else
		value = qArray[head++];
	elementNum--;
	return true;
}

