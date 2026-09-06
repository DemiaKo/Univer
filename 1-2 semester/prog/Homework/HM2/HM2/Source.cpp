#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*double n, num = 1, num1 = 1, num2 = 0; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << num << endl;
		num = num1 + num2;
		num2 = num1;
		num1 = num;
	}*/

	int num; cin >> num;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0 && i != 1 && i != num) {
			cout << "Не просте\n";
			break;
		}
		if (i == num) {
			cout << "Просте\n";
		}
	}

	return (0);
}