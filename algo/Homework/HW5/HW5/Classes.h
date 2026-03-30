#pragma once
#include <string>

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
    void push(T);
    T pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
};

std::string to_pol(std::string);
bool is_op(char);
int prior(char);
double calc(std::string);  