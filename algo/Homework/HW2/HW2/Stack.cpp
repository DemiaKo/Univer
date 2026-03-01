#include "Stack.h"
#include <iostream>

template <typename T>
void Stack<T>::resize() {
    capacity *= 2;
    T* newArray = new T[capacity];
    for (int i = 0; i <= topIndex; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

template <typename T>
Stack<T>::Stack(int cap) {
    capacity = cap;
    array = new T[capacity];
    topIndex = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template <typename T>
void Stack<T>::push(const T& el) {
    if (topIndex == capacity - 1) {
        resize();
    }
    array[++topIndex] = el;
}

template <typename T>
void Stack<T>::pop() {
    if (topIndex >= 0) {
        topIndex--;
    }
}

template <typename T>
T Stack<T>::top() const {
    if (topIndex < 0) {
        return T();
    }
    return array[topIndex];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

template <typename T>
int Stack<T>::size() const {
    return topIndex + 1;
}

template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;