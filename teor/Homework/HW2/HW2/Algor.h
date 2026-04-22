#pragma once
#include <string>
#include <iostream>

struct Rule {
    std::string from;
    std::string to;
};

std::string to_un(int a, int b) {
    std::string res = "";
    for (int i = 0; i < a; i++) {
        res += "|";
    }
    res += "*";
    for (int i = 0; i < b; i++) {
        res += "|";
    }
    return res;
}

std::string algo(int n1, int n2) {
    std::string word = to_un(n1, n2);

    std::cout << "\nПочаткове слово: " << word << "\n\n";

    std::cout << "--- Етап підготовки (Крок 4) ---\n";
    while (word.find("|*") != std::string::npos) {
        word.replace(word.find("|*"), 2, "*a");
        std::cout << word << "\n";
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

    std::cout << "\n--- Виконання основного алгоритму ---\n";
    bool applied = true;

    while (applied) {
        applied = false;

        for (int i = 0; i < 7; ++i) {
            size_t pos = word.find(rules[i].from);

            if (pos != std::string::npos) {
                word.replace(pos, rules[i].from.length(), rules[i].to);

                std::string to_print = rules[i].to.empty() ? "Л" : rules[i].to;
                std::cout << "Правило " << i + 1 << " (" << rules[i].from << " -> " << to_print << "): \t" << word << "\n";

                applied = true;
                break;
            }
        }
    }

    std::cout << "\n--- Результат ---\n";
    std::cout << "Фінальне слово: " << word << "\n";
    std::cout << "Кількість '|' (відповідь): " << word.length() << "\n";
    return word;

}