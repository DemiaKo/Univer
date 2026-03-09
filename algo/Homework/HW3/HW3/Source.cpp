#include "Class.h"
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 1. Створення таблиці та базовий запис ===" << endl;
    Table t(2, 2);

    t[0][0] = 10;
    t[0][1] = 15;
    t[1][0] = 8;
    t[1][1] = 20;

    cout << "Початкові результати:" << endl;
    cout << t;

    cout << "\n=== 2. Зміна розміру ===" << endl;
    t.resize(2, 3);
    t[0][2] = 25;
    t[1][2] = 18;
    cout << "Таблиця після resize:" << endl;
    cout << t;

    cout << "\n=== 3. Перевірка глибокого копіювання ===" << endl;
    Table backup = t;
    t[0][0] = 999;

    cout << "Оригінал (змінений):" << endl;
    cout << t;
    cout << "Резервна копія:" << endl;
    cout << backup;

    cout << "\n=== 4. Робота системи захисту ===" << endl;
    try {
        cout << "Спроба записати у неіснуючий рядок..." << endl;
        backup[5][0] = 100;
    }
    catch (const out_of_range& er) {
        cout << "Помилка: " << er.what() << endl;
    }

    try {
        cout << "Спроба створити таблицю з від'ємним розміром..." << endl;
        Table badTable(-1, 5);
    }
    catch (const invalid_argument& er) {
        cout << "Помилка: " << er.what() << endl;
    }

    return 0;
}