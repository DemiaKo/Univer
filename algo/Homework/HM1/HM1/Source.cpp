#include "Methods.h"

int main() {
	srand(time(NULL));
	int a, b, c;
	std::chrono::nanoseconds ser1(0), ser2(0), ser3(0);

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {
		a = (rand() % 100) * pow(-1, rand() % 2);
		b = (rand() % 100) * pow(-1, rand() % 2);
		c = (rand() % 100) * pow(-1, rand() % 2);
		//cout << "a = " << a << " b = " << b << " c = " << c << endl;
		Max_I(a, b, c);
	}
	auto end = std::chrono::high_resolution_clock::now();
	ser1 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {
		a = (rand() % 100) * pow(-1, rand() % 2);
		b = (rand() % 100) * pow(-1, rand() % 2);
		c = (rand() % 100) * pow(-1, rand() % 2);
		//cout << "a = " << a << " b = " << b << " c = " << c << endl;
		Max_II(a, b, c);
	}
	end = std::chrono::high_resolution_clock::now();
	ser2 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {
		a = (rand() % 100) * pow(-1, rand() % 2);
		b = (rand() % 100) * pow(-1, rand() % 2);
		c = (rand() % 100) * pow(-1, rand() % 2);
		//cout << "a = " << a << " b = " << b << " c = " << c << endl;
		Max_III(a, b, c);
	}
	end = std::chrono::high_resolution_clock::now();
	ser3 = chrono::duration_cast<chrono::nanoseconds>(end - start);

	
	ser1 /= 100000;
	ser2 /= 100000;
	ser3 /= 100000;
	
	cout << "Method 1: " << ser1.count() << " Method 2: " << ser2.count() << " Method 3: " << ser3.count() << endl;

	return(0);
}

int Max_I(int a, int b, int c) {
	int max;
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return(max);
}
int Max_II(int a, int b, int c) {
	int max;
	if (a > b)  max = a;
	else  max = b;
	if (max < c) max = c;
	return(max);
}
int Max_III(int a, int b, int c) {
	int max;
	if (a > b) {
		if (a > c) max = a;
		else max = c;
	}
	else {
		if (b > c) max = b;
		else max = c;
	}
	return(max);
}