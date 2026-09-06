#include "Classes.h"
#include <iostream>
using namespace std;

int main() {
	Curve** ar = new Curve*[3];
	ar[0] = new Line(2, 3);
	ar[1] = new Elips(1, 3);
	ar[2] = new Hyperbola(1, 3);

	int x = 2;
	for (int i = 0; i < 3; i++) {
		cout << ar[i]->calc_y(x) << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete ar[i];
	}
	delete[] ar;
}