#include "Classes.h"

ifstream fin("text1.txt");
ifstream finn("text2.txt");
ofstream fonn("text3.txt");

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void input(int* a, int n) {
	for (int i = 0; i < n; i++) {
		finn >> a[i];
	}
}

void output(int* a, int n) {
	for (int i = 0; i < n; i++) {
		fonn << a[i] << " ";
	}
}

void zam(int* a, int n) {
	int m;
	int i = 0;
	while (true) {
		if (!isPrime(a[i])) {
			m = i;
			break;
		}
		i++;
	}
	for (int i = 1; i < n; i++) {
		if (a[m] > a[i] && !isPrime(a[i])) m = i;
	}
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) a[i] = a[m];
	}
}

int Zad1() {
	cout << "Skilky? ";
	int n; cin >> n;
	Tovar* ar = new Tovar[n];
	for (int i = 0; i < n; i++) {
		fin >> ar[i];
		cout << ar[i] << endl;
	}
	cout << endl << "Max tovar is: " << max(ar, n) << endl;
	cout << "Min: " << min(ar, "ss", n) << endl;


	return(0);
}

int Zad2() {
	cout << "Skilky? ";
	int n; cin >> n;
	int* ar = new int[n];
	input(ar, n);
	zam(ar, n);
	output(ar, n);
	return(0);
}

int main() {
	cout << "Vybery zavdannija (1/2): ";
	int n; cin >> n;
	switch (n) {
	case 1: cout << "--------Zavdannia 1----------" << endl; Zad1(); break;
	case 2: cout << "--------Zavdannia 2----------" << endl; Zad2(); break;
	default: break;
	}
	
	return(0);
}