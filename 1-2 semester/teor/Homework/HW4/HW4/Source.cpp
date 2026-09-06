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
	string line;
public:
	Turing(string file, string s) : state("1"), line(s) {
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
	}

	string calc() {
		if (size == 0) return "Помилка завантаження";

		int ind = 0;
		bool end = false;
		int step = 1;

		while (!end) {
			if (state == "f") { break; }

			cout << "[Крок " << step++ << "] Стан: q" << state << endl;
			cout << "Стрічка: " << line << endl;
			cout << "         ";
			for (int i = 0; i < ind; i++) cout << " ";
			cout << "^" << endl << "------------------------" << endl;

			string s = "q" + state + "'" + string(1, line[ind]) + "'";
			int rule;

			for (rule = 0; rule < size; rule++) {
				if (ar[rule].find(s) == 0) {
					break;
				}
				else if (rule == size - 1) {
					end = true;
				}
			}
			if (end) break;

			int n = ar[rule].find(" > '") + 4;
			line[ind] = ar[rule][n];

			switch (ar[rule][n + 2]) {
			case 'R': ++ind; break;
			case 'L': --ind; break;
			case 'N': break;
			}

			if (ind < 0) {
				line.insert(0, 1, ' ');
				ind = 0;
			}
			else if (ind == line.length()) {
				line += ' ';
			}

			state = "";
			for (int i = n + 4; i < ar[rule].length(); i++) {
				state += ar[rule][i];
			}
		}

		cout << "[Крок " << step << "] МАШИНА ЗУПИНИЛАСЬ (Стан: qf)" << endl;
		cout << "Стрічка: " << line << endl;
		cout << "         ";
		for (int i = 0; i < ind; i++) cout << " ";
		cout << "^" << endl << "========================" << endl;

		size_t first = line.find_first_not_of(' ');
		size_t last = line.find_last_not_of(' ');

		if (first != string::npos && last != string::npos) {
			line = line.substr(first, (last - first + 1));
		}
		else {
			line = "0";   
		}
		return(line);
	}

	~Turing() { delete[] ar; }
};

void printMenu() {
	cout << "\n=== МАШИНА ТЮРІНГА: ГОЛОВНЕ МЕНЮ ===" << endl;
	cout << "1. Унарне додавання" << endl;
	cout << "2. Двійкове додавання" << endl;
	cout << "3. Унарне віднімання" << endl;
	cout << "4. Унарне множення" << endl;
	cout << "5. Переведення з унарної в десяткову" << endl;
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

		string result = t.calc();

		if (result != "Помилка завантаження") {
			cout << "\nФІНАЛЬНА ВІДПОВІДЬ: " << result << endl;
		}
	}

	return 0;
}