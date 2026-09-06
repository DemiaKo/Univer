#include "Class.h"

int main() {
	int* a = new int [4] {1, 2, 3, 4};
	Array ar(a, 4);
	ar.add(5, 2);
	ar.clear();
	cout << ar << endl;
}