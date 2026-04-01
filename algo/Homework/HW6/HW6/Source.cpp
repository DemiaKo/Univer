#include "Classes.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void printMenu() {
    cout << "\n=== Меню Розрідженої Матриці ===" << endl;
    cout << "1. Вивести поточну матрицю" << endl;
    cout << "2. Ввести всю матрицю (перезапис)" << endl;
    cout << "3. Задати значення елемента (через m[i][j])" << endl;
    cout << "4. Прочитати значення елемента" << endl;
    cout << "5. Видалити елемент" << endl;
    cout << "6. Перевірити глибоке копіювання" << endl;
    cout << "0. Вийти" << endl;
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    SparseMatrix<int> m(3, 3);
    int choice;

    while (true) {
        printMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Помилка вводу. Спробуйте ще раз.\n";
            continue;
        }

        try {
            if (choice == 1) {
                cout << "\nМатриця:\n" << m;
            }
            else if (choice == 2) {
                cout << "Введіть 9 елементів (3x3), розділяючи їх пробілом або Enter:\n";
                cin >> m;
                cout << "Матриця успішно оновлена!\n";
            }
            else if (choice == 3) {
                int r, c, val;
                cout << "Введіть рядок, колонку та значення (через пробіл): ";
                cin >> r >> c >> val;
                m[r][c] = val;
                cout << "Значення успішно записано!\n";
            }
            else if (choice == 4) {
                int r, c;
                cout << "Введіть рядок та колонку (через пробіл): ";
                cin >> r >> c;
                cout << "Значення m[" << r << "][" << c << "] = " << m[r][c] << endl;
            }
            else if (choice == 5) {
                int r, c;
                cout << "Введіть рядок та колонку (через пробіл): ";
                cin >> r >> c;
                m.remove(r, c);
                cout << "Значення m[" << r << "][" << c << "] видалено " << endl;
            }
            else if (choice == 6) {
                SparseMatrix<int> copy_m = m;
                copy_m[0][0] = 999;
                cout << "\nОригінал (m[0][0] не змінився):\n" << m;
                cout << "\nКопія (m[0][0] = 999):\n" << copy_m;
            }
            else if (choice == 0) {
                cout << "До побачення!\n";
                break;
            }
            else {
                cout << "Невірний вибір!\n";
            }
        }
        catch (const std::out_of_range& e) {
            cout << "ВИНЯТОК: " << e.what() << endl;
        }
        catch (const std::invalid_argument& e) {
            cout << "ВИНЯТОК: " << e.what() << endl;
        }
    }

    return 0;
}