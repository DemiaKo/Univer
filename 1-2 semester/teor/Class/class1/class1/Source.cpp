#include "Methods.h"

int main() {
	srand(time(NULL));
	int a;
	double ser1, ser2, ser3;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() % 1000000;
		Method_1(a);
	}
	auto end = chrono::high_resolution_clock::now();
	ser1 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() % 1000000;
		Method_2(a);
	}
	end = chrono::high_resolution_clock::now();
	ser2 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() % 1000000;
		Method_3(a);
	}
	end = chrono::high_resolution_clock::now();
	ser3 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();


	ser1 /= 1000000;
	ser2 /= 1000000;
	ser3 /= 1000000;

	cout << "Method_1: " << ser1 << " Method_2: " << ser2 << " Method_3: " << ser3 << endl;


	return(0);
}