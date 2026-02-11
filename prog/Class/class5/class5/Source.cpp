#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

/*float len(float x1, float y1, float x2, float y2) {
	return (sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
}

float p(float const* const* a, int n) {
	float sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += len(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
	}
	if (n > 2) sum += len(a[n - 1][0], a[n - 1][1], a[0][0], a[0][1]);
	return(sum);
}

int main() {
	int n; cin >> n;
	float** coords = new float*[n];
	for (int i = 0; i < n; i++) {
		coords[i] = new float[2];
		cout << "x = ";
		cin >> coords[i][0]; 
		cout << "y = ";
		cin >> coords[i][1];
	}
	for (int i = 0; i < n; i++) {
		cout << "x: " << coords[i][0] << " y: " << coords[i][1] << endl;
	}
	cout << p(coords, n);

	return(0);
}*/

/*void input(int**& a, int n) {
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 10;
		}
	}
}

void input(int*& a, int n) {
	a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
	}
}

void output(int const* const* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void output(int const* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void mult(int const* const* a, int const* b, int ** r, int n, int nn) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			r[nn - 1][i] += a[i][j] * b[j];
		}
	}
}

void result(int const* const * r, int n) {
	int* res = new int[n];
	for (int i = 0; i < n; i++) res[i] = 0;
	for (int j = 0; j < n; j++) {
		res[j] += r[0][j] + r[1][j];
	}
	for (int j = 0; j < n; j++) {
		res[j] = res[j] - r[2][j];
	}
	output(res, n);
}

int main() {
	srand(time(0));
	int** a, ** b, ** c, ** res, * y, * x, * z, n; cin >> n;
	input(a, n);
	output(a, n);
	cout << endl;
	input(b, n);
	output(b, n);
	cout << endl;
	input(c, n);
	output(c, n);
	cout << endl;
	input(x, n);
	output(x, n);
	cout << endl;
	input(y, n);
	output(y, n);
	cout << endl;
	input(z, n);
	output(z, n);
	cout << endl;
	res = new int* [3];
	for (int i = 0; i < 3; i++) {
		res[i] = new int[n];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = 0;
		}
	}
	mult(a, x, res, n, 1);
	mult(b, y, res, n, 2);
	mult(c, z, res, n, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	result(res, n);
}*/

float Pow(float n, float s) {
	if (s == 0) return (1);
	if (s < 0) return (1/(n * (Pow(n, abs(s)-1))));
	return (n * (Pow(n, abs(s) - 1)));
}

int main() {
	float n, s, nn; cin >> n >> s;
	nn = n;
	cout << Pow(n, s) << endl;
	return 0;
}