#include <iostream>
#include <string>
using namespace std;

template <typename T>
T max(T* a, int size) {
	T max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) max = a[i];
	}
	return(max);
}

int main() {
	char a[] = "helol";
	cout << max(a, sizeof(a) / sizeof(a[0])) << endl;


	return(0);
}