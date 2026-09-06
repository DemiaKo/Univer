#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "як тебе звати?\n";
	string name;
	getline(cin, name);
	cout << "ѕрив≥т, " << name << "!\n";

	system("pause");  
	return 0;
}