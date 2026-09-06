#include "Classes.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Queue<int> q(5);
    PriorityQueue<int> pq(5);
    int choice = -1;

    while (choice != 0) {
        cout << "\n================ МЕНЮ СТРУКТУР ДАНИХ ================\n";
        cout << "--- Звичайна черга (FIFO) ---\n";
        cout << "1. Push       2. Pop       3. Front\n";
        cout << "4. Print      5. Empty     6. Copy\n";
        cout << "--- Пріоритетна черга (Binary Heap) ---\n";
        cout << "7. Push      8. Pop      9. Top\n";
        cout << "10. Print    11. Size\n";
        cout << "0. Вихід\n";
        cout << "-----------------------------------------------------\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "[Помилка] Будь ласка, введіть число!\n";
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                int val;
                cout << "Введіть число для додавання: "; cin >> val;
                q.push(val);
                cout << "[Успіх] " << val << " додано до звичайної черги.\n";
                break;
            }
            case 2:
                cout << "[Успіх] Видалено з черги: " << q.pop() << "\n";
                break;
            case 3:
                cout << "[Інфо] Перший у черзі: " << q.front() << "\n";
                break;
            case 4:
                cout << "[Стан] Поточна черга: " << q << "\n";
                break;
            case 5:
                cout << (q.empty() ? "[Інфо] Черга порожня.\n" : "[Інфо] Черга має елементи.\n");
                break;
            case 6: {
                Queue<int> qCopy = q;
                cout << "[Успіх] Створено копію! Додаємо 999 у копію...\n";
                qCopy.push(999);
                cout << "Оригінал: " << q << "\nКопія: " << qCopy << "\n";
                break;
            }

            case 7: {
                int val, prio;
                cout << "Введіть число: "; cin >> val;
                cout << "Введіть його пріоритет (число): "; cin >> prio;
                pq.push(val, prio);
                cout << "[Успіх] Елемент " << val << " з пріоритетом " << prio << " додано.\n";
                break;
            }
            case 8:
                cout << "[Успіх] Вилучено елемент з найвищим пріоритетом: " << pq.pop() << "\n";
                break;
            case 9:
                cout << "[Інфо] На вершині (max priority): " << pq.top() << "\n";
                break;
            case 10:
                cout << "[Стан] Пріоритетна черга (структура купи): ";
                pq.print(cout);
                break;
            case 11:
                cout << "[Інфо] Кількість елементів у пріоритетній черзі: " << pq.size() << "\n";
                break;

            case 0:
                cout << "Завершення роботи...\n";
                break;
            default:
                cout << "[Помилка] Невідома команда.\n";
            }
        }
        catch (const exception& e) {
            cout << "\n!!! EXCEPTION: " << e.what() << " !!!\n";
        }
    }

    return 0;
}