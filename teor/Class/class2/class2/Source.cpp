#include <iostream>
#include <chrono>
#include <random>
#include <time.h>
using namespace std;


float calc1(int x, int n) {
	float S = 0;
	for (int i = 1; i <= n; i++) {
		S += sin(i * x);
	}
	return S;
}

float calc2(int x, int n) {
    if (x == 0) {
        return 0;
    }
    float half_x = x / 2.0f;

    return (sinf(n * half_x) * sinf((n + 1) * half_x)) / sinf(half_x);
}


int main() {
	srand(time(NULL));
	int x, n = 100;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		x =  7;
		cout << calc1(x, n) << "\n";
	}
	auto time1 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count() / 1000000;

	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		x =  7;
		cout << calc2(x, n) << "\n";
	}
	auto time2 = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count() / 1000000;

	cout << "First func: " << time1 << "nanos. \nSecond func: " << time2 << "nanos. " << endl;

}