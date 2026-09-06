#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Як тебе звати?\n";
	string name;
	getline(cin, name);
	cout << "Привіт, " << name << "!\n";

	system("pause");
	return(0);
} 
