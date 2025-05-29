#pragma once

template <typename T>
class MyQueue {
	T* data;
	size_t cap;
	size_t get;
	size_t put;
	size_t count;

	void copyFrom(const MyQueue& other);
	void moveFrom(MyQueue&& other);
	void free();

	void resize();

public:
	MyQueue();
	MyQueue(const MyQueue& other);
	MyQueue(MyQueue&& other) noexcept;
	MyQueue& operator=(const MyQueue& other);
	MyQueue& operator=(MyQueue&& other) noexcept;
	~MyQueue();

	void push(const T& obj);
	void pop();
	bool empty() const;
	const T& peek() const;
};

template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	cap = other.cap;
	get = other.get;
	put = other.put;
	count = other.count;

	data = new T[cap];

	size_t i = get;
	while (i != put) {
		data[i] = other.data[i];
		(i += 1) %= cap;
	}
}

template<typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	cap = other.cap;
	get = other.get;
	put = other.put;
	data = other.data;
	count = other.count;

	other.data = nullptr;
	other.cap = other.get = other.put;
}

template<typename T>
void MyQueue<T>::free()
{
	delete[] data;
	cap = get = put = count = 0;
}

template<typename T>
void MyQueue<T>::resize()
{
	T* temp = new T[cap*2];

	size_t i = get;
	while (i != put) {
		temp[i - get] = data[i];
		(i += 1) %= cap;
	}

	get = 0;
	put = cap;
	cap *= 2;

	delete[] data;
	data = temp;
}

template<typename T>
 MyQueue<T>::MyQueue()
{
	 cap = 8;
	 get = put = count = 0;
	 data = new T[cap];
}

template<typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
 MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
}

 template<typename T>
 MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other) noexcept
 {
	 if (this != &other) {
		 free();
		 moveFrom(std::move(other));
	 }
 }

template<typename T>
MyQueue<T>::~MyQueue()
{
	free();
}

template<typename T>
void MyQueue<T>::push(const T& obj)
{
	if (count == cap) {
		resize();
	}

	data[put] = obj;
	(put += 1) %= cap;
	count++;
}

template<typename T>
void MyQueue<T>::pop()
{
	if (empty()) {
		throw std::invalid_argument("Queue is empty");
	}

	(get += 1) %= cap;
	count--;
}

template<typename T>
bool MyQueue<T>::empty() const
{
	return count == 0;
}

template<typename T>
const T& MyQueue<T>::peek() const
{
	if (empty()) {
		throw std::invalid_argument("Queue is empty");
	}

	return data[get];
}
