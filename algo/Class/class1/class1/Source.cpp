#include "Methods.h"

int main() {
	srand(time(NULL));
	int a;
	chrono::nanoseconds ser1(0), ser2(0), ser3(0);
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() / 1000000;
		Method_1(a);
	}
	auto end = chrono::high_resolution_clock::now();
	ser1 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() / 1000000;
		Method_2(a);
	}
	end = chrono::high_resolution_clock::now();
	ser2 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		a = 1 + rand() / 1000000;
		Method_3(a);
	}
	end = chrono::high_resolution_clock::now();
	ser3 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	ser1 /= 1000000;
	ser2 /= 1000000;
	ser3 /= 1000000;

	cout << "Method_1: " << ser1.count() << " Method_2: " << ser2.count() << " Method_3: " << ser3.count() << endl;


	return(0);
}

bool Method_1(int n) {
	bool s = true;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) s = false;
	}
	return(s);
}

bool Method_2(int n, int i) {
	if (n <= 2) return (n == 2);
	if (n % i == 0) return false;
	if (i * i > n) return true;

	return Method_2(n, ++i);
}
bool Method_3(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}