#include "Classes.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string s1 = "2 + 2 * 2";
    cout << "Вираз 1: " << s1 << endl;
    cout << "ЗПЗ:     " << to_pol(s1) << endl;
    cout << "Відповідь: " << calc(to_pol(s1)) << endl;
    cout << "------------------------\n";

    string s2 = "(2 + 2) * 2";
    cout << "Вираз 2: " << s2 << endl;
    cout << "ЗПЗ:     " << to_pol(s2) << endl;
    cout << "Відповідь: " << calc(to_pol(s2)) << endl;
    cout << "------------------------\n";

    string s3 = "15 / (3 - 3)";
    cout << "Вираз 3: " << s3 << endl;
    try {
        string rpn3 = to_pol(s3);
        cout << "ЗПЗ:     " << rpn3 << endl;
        cout << "Відповідь: " << calc(rpn3) << endl;
    }
    catch (const runtime_error& e) {
        cout << "Спіймано помилку: " << e.what() << endl;
    }
    cout << "------------------------\n";

    cout << "\nВведіть власний вираз:\n> ";
    string user_s = "";
    if (getline(cin >> ws, user_s)) {
        try {
            string user_rpn = to_pol(user_s);
            cout << "Ваш ЗПЗ: " << user_rpn << endl;
            cout << "Результат: " << calc(user_rpn) << endl;
        }
        catch (const exception& e) {
            cout << "Помилка обчислення: " << e.what() << endl;
        }
    }

    return 0;
}