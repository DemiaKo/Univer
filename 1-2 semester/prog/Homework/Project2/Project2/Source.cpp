#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int i = 0;
	float sum = 0, n = 3;
	while (i < n) {
		int x;
		cin >> x;
		if (x < 0) {
			sum += x;
		}
		i++;
	}
	sum = sum / n;
	cout << sum;
}