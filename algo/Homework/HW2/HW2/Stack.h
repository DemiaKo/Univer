#pragma once

template <typename T>
class Stack {
private:
    T* array;
    int capacity;
    int topIndex;

    void resize();

public:
    Stack(int = 2);
    ~Stack();

    void push(const T&);
    void pop();
    T top() const;

    bool isEmpty() const;
    int size() const;
};