#pragma once
#include <iostream>

template <typename T>
class Queue {
private:
	T* array;
	int cap;
	int head = 0;
	int tail = 0;
	void resize();
public:
	Queue(int = 5);
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	T front() const;
	bool empty() const;
	void push(T);
	T pop();
	void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream& os, const Queue& t) { t.print(os); return(os); }
	~Queue() { delete[] array; }
};


template <typename T>
struct Element {
    T data;
    int priority;
};

template <typename T>
class PriorityQueue {
private:
    Element<T>* array;
    int cap;
    int count;
    void resize();
    void siftUp(int);
    void siftDown(int);
public:
    PriorityQueue(int = 10);
    ~PriorityQueue();
    void push(T, int);
    T pop();
    T top() const;
    bool empty() const;
    int size() const;
    void print(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& t) { t.print(os); return(os); }
};