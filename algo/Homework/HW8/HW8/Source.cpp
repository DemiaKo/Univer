#include <iostream>
#include <Windows.h>
#include "Classes.h"

using namespace std;

void printMenu() {
    cout << "\n========== МЕНЮ ==========\n";
    cout << "1. Додати елемент у множину A\n";
    cout << "2. Додати елемент у множину B\n";
    cout << "3. Видалити елемент з множини A\n";
    cout << "4. Видалити елемент з множини B\n";
    cout << "5. Вивести обидві множини\n";
    cout << "6. Об'єднання (A U B)\n";
    cout << "7. Перетин (A n B)\n";
    cout << "8. Різниця (A \\ B)\n";
    cout << "9. Симетрична різниця XOR (A ^ B)\n";
    cout << "0. Вихід\n";
    cout << "==========================\n";
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    CustomSet<int> setA;
    CustomSet<int> setB;
    int choice;
    int val;

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
                cout << "Введіть число для додавання в A: ";
                cin >> val;
                if (setA.insert(val)) cout << "[+] Елемент успішно додано.\n";
                else cout << "[-] Елемент вже існує у множині A.\n";
                break;
            case 2:
                cout << "Введіть число для додавання в B: ";
                cin >> val;
                if (setB.insert(val)) cout << "[+] Елемент успішно додано.\n";
                else cout << "[-] Елемент вже існує у множині B.\n";
                break;
            case 3:
                cout << "Введіть число для видалення з A: ";
                cin >> val;
                setA.erase(val);
                cout << "[+] Елемент видалено з A.\n";
                break;
            case 4:
                cout << "Введіть число для видалення з B: ";
                cin >> val;
                setB.erase(val);
                cout << "[+] Елемент видалено з B.\n";
                break;
            case 5:
                cout << "\nSet A: " << setA;
                cout << "Set B: " << setB;
                break;
            case 6:
                cout << "\nUnion (A U B): " << setA.unionWith(setB);
                break;
            case 7:
                cout << "\nIntersection (A n B): " << setA.intersectWith(setB);
                break;
            case 8:
                cout << "\nDifference (A \\ B): " << setA.differenceWith(setB);
                break;
            case 9:
                cout << "\nXOR (A ^ B): " << setA.xorWith(setB);
                break;
            case 0:
                cout << "Вихід з програми...\n";
                return 0;
            default:
                cout << "\n[!] Невідома команда. Спробуйте ще раз.\n";
            }
        }
        catch (const std::exception& e) {
            cout << "\n[EXC] Перехоплено виняток: " << e.what() << "\n";
        }
    }

    return 0;
}