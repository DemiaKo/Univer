#include "Classes.h"
#include <string>
#include <stdexcept>

template<typename T>
Queue<T>::Queue(int c) {
	if (c <= 0) {
		throw std::invalid_argument("Розмір черги має бути більшим за нуль");
	}
	cap = c;
	array = new T[cap]{ T{} };
	head = 0;
	tail = 0;
}

template<typename T>
void Queue<T>::resize() {
	T* a = new T[cap * 2]{ T{} };
	int j = 0, i = head;

	while (i != tail) {
		a[j++] = array[i];
		i = (i + 1) % cap;
	}

	head = 0;
	tail = j;
	cap *= 2;
	delete[] array;
	array = a;
}

template <typename T>
Queue<T>::Queue(const Queue& other) {
	this->cap = other.cap;
	this->array = new T[this->cap]{ T{} };
	this->head = 0;
	int j = 0, i = other.head;

	while (i != other.tail) {
		this->array[j++] = other.array[i];
		i = (i + 1) % other.cap;
	}

	this->tail = j;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this == &other) return(*this);

	this->cap = other.cap;
	delete[] this->array;
	this->array = new T[this->cap]{ T{} };
	this->head = 0;
	int j = 0, i = other.head;

	while (i != other.tail) {
		this->array[j++] = other.array[i];
		i = (i + 1) % other.cap;
	}

	this->tail = j;
	return(*this);
}

template<typename T>
T Queue<T>::front() const {
	if (head == tail) {
		throw std::out_of_range("Черга порожня, немає першого елемента");
	}
	return array[head];
}

template<typename T>
void Queue<T>::push(T n) {
	if ((tail + 1) % cap == head) {
		resize();
	}
	array[tail] = n;
	tail = (tail + 1) % cap;
}

template<typename T>
T Queue<T>::pop() {
	if (head == tail) {
		throw std::out_of_range("Empty queue");
	}
	T x = array[head];
	head = (head + 1) % cap;
	return(x);
}

template<typename T>
bool Queue<T>::empty() const {
	return head == tail;
}

template<typename T>
void Queue<T>::print(std::ostream& os) const {
	os << "{ ";
	int i = head;
	while (i != tail) {
		os << array[i] << " ";
		i = (i + 1) % cap;
	}
	os << "}";
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int size) : cap(size), count(0) {
	if (size <= 0) throw std::invalid_argument("Розмір має бути > 0");
	array = new Element<T>[cap];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
	delete[] array;
}

template <typename T>
void PriorityQueue<T>::resize() {
	cap *= 2;
	Element<T>* newArray = new Element<T>[cap];
	for (int i = 0; i < count; i++) newArray[i] = array[i];
	delete[] array;
	array = newArray;
}

template <typename T>
void PriorityQueue<T>::siftUp(int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (array[index].priority <= array[parent].priority) break;

		std::swap(array[index], array[parent]);
		index = parent;
	}
}

template <typename T>
void PriorityQueue<T>::siftDown(int index) {
	while (2 * index + 1 < count) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int j = left;

		if (right < count && array[right].priority > array[left].priority) {
			j = right;
		}

		if (array[index].priority >= array[j].priority) break;

		std::swap(array[index], array[j]);
		index = j;
	}
}

template <typename T>
void PriorityQueue<T>::push(T data, int priority) {
	if (count == cap) resize();
	array[count] = { data, priority };
	siftUp(count);
	count++;
}

template <typename T>
T PriorityQueue<T>::pop() {
	if (empty()) throw std::out_of_range("Черга порожня");
	T result = array[0].data;
	array[0] = array[count - 1];
	count--;
	if (!empty()) siftDown(0);
	return result;
}

template <typename T>
T PriorityQueue<T>::top() const {
	if (empty()) throw std::out_of_range("Черга порожня");
	return array[0].data;
}

template <typename T>
bool PriorityQueue<T>::empty() const { return count == 0; }

template <typename T>
int PriorityQueue<T>::size() const { return count; }

template <typename T>
void PriorityQueue<T>::print(std::ostream& os) const {
	os << "{ ";
	for (int i = 0; i < count; i++) {
		os << array[i].data << "[p:" << array[i].priority << "] ";
	}
	os << "}";
}

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<std::string>;
template class PriorityQueue<int>;
template class PriorityQueue<float>;
template class PriorityQueue<char>;
template class PriorityQueue<std::string>;