#include <Windows.h>
#include"Classes.h"

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	ifstream file("text.txt");
	Computer** ar = nullptr;
	int n = fromFile(file, ar);
	for (int i = 0; i < n; i++) {
		cout << *ar[i] << endl;
	}

	return(0);
}