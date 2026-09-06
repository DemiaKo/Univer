#include "Classes.h"
#include <iostream>
#include <stdexcept>

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
void Stack<T>::push(T el) {
    if (topIndex == capacity - 1) {
        resize();
    }
    array[++topIndex] = el;
}

template <typename T>
T Stack<T>::pop() {
    if (topIndex >= 0) {
        topIndex--;
    }
    return(array[topIndex+1]);
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

std::string to_pol(std::string s) {
    Stack<char> st;
    std::string res = "";
    bool may_be_unary = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        else if (isdigit(s[i])) {
            while (i < s.length() && (isdigit(s[i]) || s[i]=='.')) {
                res += s[i++];
            }
            res += " ";
            i--;
            may_be_unary = false;
        }
        else if (is_op(s[i])) {
            char op = s[i];
            if (op == '-' && may_be_unary) {
                op = '~';             
            }
            if (st.isEmpty()) {
                st.push(op);
            }
            else if (prior(st.top()) < prior(op)) {
                st.push(op);
            }
            else if (prior(st.top()) >= prior(op)) {
                while (!st.isEmpty() && prior(st.top()) >= prior(op)) {
                    res = res + st.pop() + " ";
                }
                st.push(op);
            }
            may_be_unary = true;
        } 
        else if (s[i] == '(') {
            st.push(s[i]);
            may_be_unary = true;
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                res = res + st.pop() + " ";
            }
            st.pop();
            may_be_unary = false;
        }
    }
    while (!st.isEmpty()) res = res + st.pop() + " ";
    return(res);
}

bool is_op(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '~') return true;
    return false;
}

int prior(char c)
{
    if (c == '+' || c == '-') return(1);
    if (c == '*' || c == '/') return(2);
    if (c == '~') return(3);
    if (c == '^') return(4);
    return(0);
}

double calc(std::string s) {
    Stack<double> st;
    double res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        else if (isdigit(s[i])) {
            std::string t = "";
            while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                t += s[i++];
            }
            st.push(std::stod(t));
            i--;
        }
        else if (is_op(s[i])) {
            if (s[i] == '~') {
                double n = st.pop();
                st.push(-n);
            }
            else {
                double n2 = st.pop(), n1 = st.pop();
                switch (s[i]) {
                case '+': st.push(n1 + n2); break;
                case '-': st.push(n1 - n2); break;
                case '*': st.push(n1 * n2); break;
                case '/':
                    if (n2 == 0) {
                        throw std::runtime_error("Ділення на нуль!");
                    }
                    st.push(n1 / n2);
                    break;
                case '^': st.push(pow(n1, n2)); break;
                }
            }
        }
    }
    return(st.pop());
}

template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
template class Stack<char>;