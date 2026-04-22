#include <iostream>
#include <Windows.h>
#include "Graph.h"

using namespace std;

void printMenu() {
    cout << "\n========== АЛГОРИТМ ДЕЙКСТРИ ==========\n";
    cout << "1. Створити новий граф (вказати кількість вершин)\n";
    cout << "2. Додати ребро\n";
    cout << "3. Запустити алгоритм Дейкстри\n";
    cout << "4. Вивести матрицю суміжності\n";
    cout << "0. Вихід\n";
    cout << "========================================\n";
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Graph* g = nullptr;
    int choice;

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cout << "\n[!] Помилка: Введіть числове значення.\n";
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                int v;
                cout << "Введіть кількість вершин: ";
                cin >> v;
                if (g != nullptr) delete g;
                g = new Graph(v);
                cout << "[+] Граф на " << v << " вершин створено.\n";
                break;
            }
            case 2: {
                if (!g) { cout << "[-] Спочатку створіть граф!\n"; break; }
                int u, v, weight;
                cout << "Введіть (початок, кінець, вага) через пробіл: ";
                cin >> u >> v >> weight;
                g->addEdge(u, v, weight);
                cout << "[+] Ребро додано.\n";
                break;
            }
            case 3: {
                if (!g) { cout << "[-] Спочатку створіть граф!\n"; break; }
                int start;
                cout << "Введіть стартову вершину: ";
                cin >> start;
                int* dist = g->dijkstra(start);
                cout << "\nНайкоротші відстані від вершини " << start << ":\n";
                for (int i = 0; i < g->getNumVertices(); ++i) {
                    if (dist[i] == INT_MAX)
                        cout << "До " << i << " -> Недосяжна\n";
                    else
                        cout << "До " << i << " -> " << dist[i] << "\n";
                }
                delete[] dist;
                break;
            }
            case 4: {
                if (!g) { cout << "[-] Спочатку створіть граф!\n"; break; }
                cout << "\nМатриця суміжності (X = немає ребра):\n";
                g->printMatrix(cout);
                break;
            }
            case 0:
                if (g != nullptr) delete g;
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