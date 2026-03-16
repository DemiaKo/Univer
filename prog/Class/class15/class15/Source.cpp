#include "Classes.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	ifstream fin("txt.txt");

    Clock** cl = nullptr;
	int n = fromFile(fin, cl);
	for (int i = 0; i < n; i++) {
		cout << *cl[i] << endl;
	}
	
	Sort_model(cl, n);

	for (int i = 0; i < n; i++) {
		cout << *cl[i] << endl;
	}

	cout << *search(cl, n);

	PrintByBatType(cl, n, "dwq x");
	PrintByBrand(cl, n, "Br ce");


	for (int i = 0; i < n; ++i) {
		delete cl[i];
	}
	delete[] cl;

	return(0);
}