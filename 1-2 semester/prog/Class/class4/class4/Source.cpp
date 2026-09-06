#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

/*void print_ar(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(2) << a[i][j] << " ";
		}
		cout << endl;
	}
}

void input_ar(int**& a, int& n, int& m) {
	if (n == 0 && m == 0) cin >> n >> m;
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 10;
		}
	}
}

void sum_ar(int** a, int** b, int**& c, int n, int m) {
	c = new int* [n];
	for (int i = 0; i < n; i++) {
		c[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int main() {
	srand(time(0));
	int** ara,** arb, **arc;
	int n = 0, m = 0;
	input_ar(ara, n, m);
	input_ar(arb, n, m);
	print_ar(ara, n, m);
	cout << endl;
	print_ar(arb, n, m);
	cout << endl;
	sum_ar(ara, arb, arc, n, m);
	print_ar(arc, n, m);
	return (0);
}*/

void Sort(int* a, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) swap(a[i], a[j]);
		}
	}
}

int main() {
	srand(time(0));
	int n; cin >> n;
	int* ar = new int[n];
	for (int i = 0; i < n; i++) {
		ar[i] = (rand() % 100) * pow(-1, rand()%2);
	}
	Sort(ar, n);
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	for (int i = 0; i < n; i++) {
		ar[i] = (rand() % 100) * pow(-1, rand() % 2);
	}
	sort(ar, ar + n, [](int x, int y) {return (x > y); });
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}


	return(0);
}
