#include "Stack.h"
#include <iostream>
#include <stack>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    cout << "--- Демонстрація ВЛАСНОГО стеку ---" << endl;
    Stack<int> myStack;

    cout << "Стек порожній? " << (myStack.isEmpty() ? "Так" : "Ні") << endl;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Додали 10, 20, 30. Розмір стеку: " << myStack.size() << endl;

    cout << "Верхній елемент: " << myStack.top() << endl;

    myStack.pop();
    cout << "Видалили верхній елемент. Новий верхній елемент: " << myStack.top() << endl;
    cout << "Новий розмір: " << myStack.size() << endl;
    cout << "Стек порожній? " << (myStack.isEmpty() ? "Так" : "Ні") << endl;
    cout << endl;

    cout << "--- Демонстрація стеку з STL ---" << endl;
    stack<int> stlStack;

    cout << "Стек порожній? " << (stlStack.empty() ? "Так" : "Ні") << endl;

    stlStack.push(10);
    stlStack.push(20);
    stlStack.push(30);
    cout << "Додали 10, 20, 30. Розмір стеку: " << stlStack.size() << endl;

    cout << "Верхній елемент (top): " << stlStack.top() << endl;

    stlStack.pop();
    cout << "Видалили верхній елемент (pop). Новий верхній елемент: " << stlStack.top() << endl;
    cout << "Новий розмір: " << stlStack.size() << endl;
    cout << "Стек порожній? " << (stlStack.empty() ? "Так" : "Ні") << endl;

    return(0);
}