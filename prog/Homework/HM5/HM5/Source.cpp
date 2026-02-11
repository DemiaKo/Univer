#include <iostream>
#include <ctime>
using namespace std;

/*int Pow(int n, int s) {
	if (s == 0) return (1);
	return (n * (Pow(n, s-1)));
}

int main() {
	int n, s, nn; cin >> n >> s;
	nn = n;
	cout << Pow(n, s) << endl;
	for (int i = 1; i < s; i++) {
		nn *= n;
	}
	cout << nn << endl;
	return 0;
}*/

void input(int**& ar, int& n, int& m) {
	cin >> n >> m;
	ar = new int* [n];
	for (int i = 0; i < n; i++) {
		ar[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ar[i][j] = rand() % 10;
		}
	}
}

void output(const int* const* ar, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}

void mult(const int* const* ar1, const int* const* ar2, int**& ar3, int n1, int m1, int n2, int m2) {
	if (m1 != n2) { 
		cout << "Incorrect arrays` sizes" << endl;
		return;
	}
	ar3 = new int* [n1];
	for (int i = 0; i < n1; i++) {
		ar3[i] = new int[m2];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) ar3[i][j] = 0;
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < m1; k++) {
				ar3[i][j] += ar1[i][k] * ar2[k][j];
			}
		}
	}
}

int main() {
	srand(time(0));
	int **ar1, **ar2, **ar3, n1, m1, n2, m2;
	input(ar1, n1, m1);
	output(ar1, n1, m1);
	cout << endl;
	input(ar2, n2, m2);
	output(ar2, n2, m2);
	cout << endl;
	mult(ar1, ar2, ar3, n1, m1, n2, m2);
	output(ar3, n1, m2);

	return(0);
}