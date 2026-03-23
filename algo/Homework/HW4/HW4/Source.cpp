#include "Classes.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

// Допоміжна функція для виводу меню на екран
void printMenu() {
    cout << "\n=== Меню Хеш-таблиці ===" << endl;
    cout << "1. Додати або оновити елемент" << endl;
    cout << "2. Знайти значення за ключем" << endl;
    cout << "3. Видалити елемент" << endl;
    cout << "4. Вивести всю таблицю на екран" << endl;
    cout << "0. Вийти з програми" << endl;
    cout << "Оберіть дію: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Table t;
    int choice;
    string key;
    int value;

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Помилка: введіть номер пункту меню!" << endl;
            continue;
        }

        if (choice == 0) {
            cout << "Вихід з програми. Навседобре!" << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Введіть ключ (слово): ";
            cin >> key;
            cout << "Введіть значення (ціле число): ";

            while (!(cin >> value)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Помилка: значення має бути числом. Введіть ще раз: ";
            }

            t.insert(key, value);
            cout << "[Успіх] Елемент [" << key << " : " << value << "] записано!" << endl;
            break;

        case 2:
            cout << "Введіть ключ для пошуку: ";
            cin >> key;
            try {
                int res = t.get(key);
                cout << "--> Знайдено значення: " << res << endl;
            }
            catch (const out_of_range& e) {
                cout << "[Помилка] " << e.what() << endl;
            }
            break;

        case 3:
            cout << "Введіть ключ для видалення: ";
            cin >> key;
            try {
                t.remove(key);
                cout << "[Успіх] Елемент з ключем '" << key << "' видалено." << endl;
            }
            catch (const out_of_range& e) {
                cout << "[Помилка] " << e.what() << endl;
            }
            break;

        case 4:
            cout << "\n--- Вміст хеш-таблиці ---" << endl;
            cout << t;
            cout << "-------------------------" << endl;
            break;

        default:
            cout << "[Помилка] Невідома команда. Оберіть число від 0 до 4." << endl;
            break;
        }
    }

    return 0;
}