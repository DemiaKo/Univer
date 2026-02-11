#include <iostream>
#include <ctime>
using namespace std;

int main() {
	/*double eps = 0.00000001, x, xp, sum, a, b, h; cin >> a >> b >> h;
	x = a;
	do {
		xp = 1, sum = 1;
		for (int n = 1; abs(xp) >= eps; n++) {
			xp *= (x * x) / (4 * (n * n) - 2 * n);
			sum += xp;
		}
		cout << "cosh(" << x << ") = " << sum << endl;
		cout << "cosh(" << x << ") = " << cosh(x) << endl;
		x += h;
	} while (x <= b);*/

	/*float n; cin >> n;
	float serg = 1;
	for (int i = 0; i < n; i++) {
		float x; cin >> x;
		if (x > 0) {
			serg *= x;
		}
		else {
			n--;
		}
	}
	serg = pow(serg, 1 / n);
	cout << serg << endl;*/

	srand(time(NULL));
	const int a = 400, b = 300;
	int n[a][b], m[a][b];
	float s = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			n[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << n[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			m[i][j] = n[i][j];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			n[i][j] = m[i][b - j - 1];
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << n[i][j] << " ";
		}
		cout << endl;
	}

	return(0);
}