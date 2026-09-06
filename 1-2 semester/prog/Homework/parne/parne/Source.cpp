#include <iostream>
using namespace std;

int main() {
	double eps = 0.00001, x, v = 1;	cin >> x;
	double l = 0;
	for (int n = 0; x >= eps; n++) {
		for (int i = 1; i <= n; i++) {
			v *= i;
		}
		l += pow(x, n) / v;
	}
	cout << l << endl;

	return 0;
}