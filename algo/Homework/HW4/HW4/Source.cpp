#include "Classes.h"
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Table t = {};

    t.insert("Orange", 2);
    t.insert("Apple", 3);

    t["Banana"] = 6;
    t["Apple"] = 100;

    cout << "--- Поточна таблиця ---" << endl;
    cout << t << endl;

    cout << "--- Перевірка пошуку ---" << endl;
    try {
        cout << "Banana value: " << t.get("Banana") << endl;
        cout << "Kiwi value: " << t.get("Kiwi") << endl;
    }
    catch (const std::out_of_range& e) {
        cout << "Спіймано виняток: " << e.what() << endl;
    }

    cout << "\n--- Перевірка видалення ---" << endl;
    t.remove("Orange");
    cout << "Таблиця після видалення Orange:" << endl;
    cout << t << endl;

    try {
        t.remove("Mango");
    }
    catch (const std::out_of_range& e) {
        cout << "Спіймано виняток при видаленні: " << e.what() << endl;
    }

    return 0;
}