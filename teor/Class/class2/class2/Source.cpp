#include <iostream>
#include <chrono>
#include <random>
#include <time.h>
using namespace std;


void calc1(int x, int n) {
	float y = 0;
	for (int i = 2; i <= n; i++)
		y += pow(cos(x), i);
}

void calc2(int x, int n) {
	float y = 0, t = cos(x);
	for (int i = 2; i <= n; i++)
		y += pow(t, i);
}

void calc3(int x, int n) {
	float y = cos(x), p = y, t = y;
	for (int i = 2; i <= n; i++) {
		p *= t;
		y += p;
	}
}

int main() {
	srand(time(NULL));
	int x, n = 100;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		x =rand() % 7;
		calc1(x, n);
	}
	auto time1 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count() / 1000000;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		x = rand() % 7;
		calc2(x, n);
	}
	auto time2 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count() / 1000000;
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		x =rand() % 7;
		calc3(x, n);
	}
	auto time3 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count() / 1000000;

	cout << time1 << " " << time2 << " " << time3 << endl;

}