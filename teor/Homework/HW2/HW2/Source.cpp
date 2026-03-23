#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Rule {
    string from;
    string to;
};

string to_un(int a, int b) {
    string res = "";
    for (int i = 0; i < a; i++) {
        res += "|";
    }
    res += "*";
    for (int i = 0; i < b; i++) {
        res += "|";
    }
    return res;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int n1, n2;
    string word;

    cout << "Введіть два числа через пробіл: ";
    cin >> n1 >> n2;

    word = to_un(n1, n2);

    cout << "\nПочаткове слово: " << word << "\n\n";

    cout << "--- Етап підготовки (Крок 4) ---\n";
    while (word.find("|*") != string::npos) {
        word.replace(word.find("|*"), 2, "*a");
        cout << word << "\n";
    }

    Rule rules[7] = {
        {"b|", "|b"},
        {"a|", "|ba"},
        {"a", ""},
        {"|*", "*a"},
        {"*|", "*"},
        {"*", ""},
        {"b", "|"}
    };

    cout << "\n--- Виконання основного алгоритму ---\n";
    bool applied = true;

    while (applied) {
        applied = false;

        for (int i = 0; i < 7; ++i) {
            size_t pos = word.find(rules[i].from);

            if (pos != string::npos) {
                word.replace(pos, rules[i].from.length(), rules[i].to);

                string to_print = rules[i].to.empty() ? "Л" : rules[i].to;
                cout << "Правило " << i + 1 << " (" << rules[i].from << " -> " << to_print << "): \t" << word << "\n";

                applied = true;
                break;
            }
        }
    }

    cout << "\n--- Результат ---\n";
    cout << "Фінальне слово: " << word << "\n";
    cout << "Кількість '|' (відповідь): " << word.length() << "\n";

    return 0;
}