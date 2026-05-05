#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Turing {
private:
    string state;
    string* ar;
    int size;
    string* line;
public:
    int lines;

    Turing(string file, string s) : state("q1") {
        ifstream f;
        f.open(file);

        if (!f.is_open()) {
            cout << "ПОМИЛКА: Не вдалося знайти файл '" << file << "'!" << endl;
            size = 0;
            return;
        }

        f >> size;
        ar = new string[size];
        for (int i = 0; i < size; i++) {
            getline(f >> ws, ar[i]);
        }

        int x = ar[0].find("'");
        lines = 0;
        while (ar[0][x] != '>') {
            if (ar[0][x] == '\'') {
                lines++;
            }
            x++;
        }
        lines /= 2;
        line = new string[lines];

        line[0] = (s.empty()) ? " " : s;
        for (int i = 1; i < lines; i++) {
            line[i] = " ";
        }
    }

    string* calc() {
        if (size == 0) return nullptr;

        int* ind = new int[lines] { 0 };
        bool end = false;
        int step = 1;

        while (!end) {
            if (state == "qf") break;

            cout << "[Крок " << step++ << "] Стан: " << state << endl;
            for (int i = 0; i < lines; i++) {
                cout << "Стрічка_" << i + 1 << ": " << line[i] << endl;
                cout << "           ";
                for (int j = 0; j < ind[i]; j++) cout << " ";
                cout << "^" << endl;
            }
            cout << "------------------------" << endl;

            string s_rule = state;
            for (int i = 0; i < lines; i++) {
                s_rule += "'" + string(1, line[i][ind[i]]) + "'";
            }

            int rule;
            for (rule = 0; rule < size; rule++) {
                if (ar[rule].find(s_rule) == 0) {
                    break;
                }
                else if (rule == size - 1) {
                    end = true;
                }
            }
            if (end) break;

            int base_index = ar[rule].find(" > '");
            int dir_start = base_index + 3 + (lines * 3);

            for (int i = 0; i < lines; i++) {
                int char_index = base_index + 4 + (i * 3);
                line[i][ind[i]] = ar[rule][char_index];

                char dir = ar[rule][dir_start + i];
                if (dir == 'R') {
                    ind[i]++;
                }
                else if (dir == 'L') {
                    ind[i]--;
                }
            }

            state = "";
            for (int i = dir_start + lines; i < ar[rule].length(); i++) {
                state += ar[rule][i];
            }

            for (int i = 0; i < lines; i++) {
                if (ind[i] < 0) {
                    line[i].insert(0, 1, ' ');
                    ind[i] = 0;
                }
                else if (ind[i] >= line[i].length()) {
                    line[i] += ' ';
                }
            }
        }

        cout << "[Крок " << step << "] МАШИНА ЗУПИНИЛАСЬ (Стан: " << state << ")" << endl;

        for (int i = 0; i < lines; i++) {
            size_t first = line[i].find_first_not_of(' ');
            size_t last = line[i].find_last_not_of(' ');
            if (first != string::npos && last != string::npos) {
                line[i] = line[i].substr(first, (last - first + 1));
            }
            else {
                line[i] = "0";
            }
        }

        delete[] ind;
        return line;
    }

    ~Turing() {
        delete[] ar;
        delete[] line;
    }
};

void printMenu() {
	cout << "\n=== МАШИНА ТЮРІНГА: ГОЛОВНЕ МЕНЮ ===" << endl;
	cout << "1. Паліндроми" << endl;
	cout << "2. Двійкове додавання" << endl;
	cout << "3. Квадрат символів" << endl;
	cout << "4. Десяткове віднімання" << endl;
	cout << "5. Двійкове ділення" << endl;
	cout << "0. Вийти з програми" << endl;
	cout << "====================================" << endl;
	cout << "Ваш вибір (0-5): ";
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int choice;

	while (true) {
		printMenu();
		cin >> choice;

		if (choice == 0) {
			cout << "Вихід з емулятора. До зустрічі!" << endl;
			break;
		}

		if (choice < 1 || choice > 5) {
			cout << "Помилка: такого алгоритму немає. Спробуйте ще раз." << endl;
			continue;
		}

		string fileName = to_string(choice) + ".txt";

		cout << "Введіть початкову стрічку: ";
		string v;
		getline(cin >> ws, v);

		cout << "\n>>> ЗАПУСК МАШИНИ (" << fileName << ") <<<\n" << endl;
		Turing t(fileName, v);

		string* result = t.calc();

		if (result != nullptr) {
			cout << "\nФІНАЛЬНА ВІДПОВІДЬ:" << endl;
			for (int i = 0; i < t.lines; i++) {
				cout << result[i] << endl;
			}
		}
	}

	return 0;
} 