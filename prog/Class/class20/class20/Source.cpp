#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

void task1() {
    vector<int> v = { 5, 2, 8, 2, 1, 5, 9, 1 };

    sort(v.begin(), v.end());

    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());

    cout << "Завдання 1: ";
    for (int num : v) cout << num << " ";
    cout << "\n";
}

struct Student {
    string name;
    int grade;
};

void task2() {
    vector<Student> students = {
        {"Іван", 85}, {"Марія", 95}, {"Олег", 85}, {"Анна", 90}
    };

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.grade != b.grade) {
            return a.grade > b.grade;
        }
        return a.name < b.name;
        });

    cout << "Завдання 2:\n";
    for (const auto& s : students) {
        cout << s.name << " - " << s.grade << "\n";
    }
}

void task3() {
    vector<int> v1 = { 1, 3, 5, 7, 9 };
    vector<int> v2 = { 2, 3, 4, 5, 8, 9 };
    vector<int> result;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        back_inserter(result));

    cout << "Завдання 3: ";
    for (int num : result) cout << num << " ";
    cout << "\n";
}

void task4() {
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };

    v.erase(remove_if(v.begin(), v.end(), [](int x) {
        return x % 2 != 0;
        }), v.end());

    cout << "Завдання 4: ";
    for (int num : v) cout << num << " ";
    cout << "\n";
}

void task5() {
    vector<int> v = { 1, 3, 2, 3, 4, 3, 2, 1, 3, 5 };

    if (v.empty()) return;

    sort(v.begin(), v.end());

    int max_count = 1;
    int current_count = 1;
    int most_frequent = v[0];

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            current_count++;
        }
        else {
            if (current_count > max_count) {
                max_count = current_count;
                most_frequent = v[i - 1];
            }
            current_count = 1;
        }
    }

    if (current_count > max_count) {
        max_count = current_count;
        most_frequent = v.back();
    }

    cout << "Завдання 5: Найчастіше число - " << most_frequent
        << " (зустрічається " << max_count << " разів)\n";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    task1();
    task2();
    task3();
    task4();
    task5();

    return(0);
}