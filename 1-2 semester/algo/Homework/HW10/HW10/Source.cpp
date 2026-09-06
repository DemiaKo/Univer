#include <iostream>
#include <Windows.h>
#include "AVLTree.h"

using namespace std;

void printMenu() {
    cout << "\n========== AVL-ДЕРЕВО ==========\n";
    cout << "1. Додати елемент (Insert)\n";
    cout << "2. Видалити елемент (Remove)\n";
    cout << "3. Знайти елемент (Contains)\n";
    cout << "4. Вивести дерево на екран\n";
    cout << "5. Очистити та створити нове дерево\n";
    cout << "0. Вихід\n";
    cout << "================================\n";
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    AVLTree tree;
    int choice, val;

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cout << "\n[!] Помилка: Введіть числове значення.\n";
            continue;
        }

        try {
            switch (choice) {
            case 1:
                cout << "Введіть число для додавання: ";
                cin >> val;
                tree.insert(val);
                cout << "[+] Елемент " << val << " успішно додано.\n";
                break;
            case 2:
                cout << "Введіть число для видалення: ";
                cin >> val;
                tree.remove(val);
                cout << "[+] Елемент " << val << " видалено. Дерево збалансовано.\n";
                break;
            case 3:
                cout << "Введіть число для пошуку: ";
                cin >> val;
                if (tree.contains(val)) cout << "[+] Елемент знайдено у дереві.\n";
                else cout << "[-] Елемент відсутній.\n";
                break;
            case 4:
                cout << "\nСтруктура дерева (повернута на 90 градусів):\n";
                tree.print(cout);
                break;
            case 5:
                tree = AVLTree();
                cout << "[+] Дерево повністю очищено.\n";
                break;
            case 0:
                cout << "Вихід...\n";
                return 0;
            default:
                cout << "\n[!] Невідома команда.\n";
            }
        }
        catch (const exception& e) {
            cout << "\n[EXC] Помилка: " << e.what() << "\n";
        }
    }

    return 0;
}