#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <Windows.h>
using namespace std;


void zav3() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    map<string, set<string>> data;
    string line;

    while (getline(in, line)) {
        int dash = line.find('-');
        string country = line.substr(0, dash);
        string river = line.substr(dash + 1);
        data[river].insert(country);
    }

    for (const auto& pair : data) {
        const string& river_name = pair.first;
        const set<string>& countries = pair.second;

        out << river_name << "\n";
        out << countries.size() << "\n";

        auto it = countries.begin();
        while (it != countries.end()) {
            out << *it;
            it++;
            if (it != countries.end()) out << ", ";
        }
        out << "\n--------------------------\n";
    }
}

void zav2() {
    vector<double> v = { -5.5, 2.0, 8.0, 1.5, -2.0, 4.0 };

    auto min_it = min_element(v.begin(), v.end());

    double dob = 1;
    int count = 0;

    for (double x : v) {
        if (x > 0) {
            dob *= x;
            count++;
        }
    }

    double geom = pow(dob, 1.0 / count);
    cout << *min_it << " " << geom << endl;
    *min_it = geom;

    for (double x : v) cout << x << " ";
    cout << endl;
}

void zav1() {
    int u[] = { 2, 40, 3, 2, 40, 2, 23, 1, 2 };
    int n = sizeof(u) / sizeof(u[0]);

    deque<int> a(u + 1, u + n - 1);

    for (int x : a) cout << x << " ";
    cout << endl;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int x : a) cout << x << " ";
    cout << endl;

    int sum = accumulate(a.begin(), a.end(), 0, [](int acc, int val) {
        return (val > 3) ? acc + val : acc;
        });

    cout << sum << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    zav1();

    return(0);
}