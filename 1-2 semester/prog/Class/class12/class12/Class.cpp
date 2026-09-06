#include "Class.h"
#include <algorithm>
#include <stdexcept>

Array::Array() {
	n = 0;
	a = nullptr;
}

Array::Array(const Array& ar) {
	n = ar.n;
	if (n > 0) {
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = ar.a[i];
		}
	} else {
		a = nullptr;
	}
}

Array::Array(int num) {
	n = num;
	if (n > 0) {
		a = new int[n] {0};
	} else {
		a = nullptr;
	}
}

Array::Array(int* ar, int num) {
	n = num;
	if (n > 0) {
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = ar[i];
		}
	} else {
		a = nullptr;
	}
}

int Array::operator[](int nn) {
	if (nn < 0 || nn >= n) throw std::out_of_range("Array index out of range");
	return a[nn];
}

Array::~Array() {
	delete[]a;
	a = nullptr;
	n = 0;
}

Array& Array::add(int num) {
	int* ar = new int[n+1];
	for (int i = 0; i < n; i++) ar[i] = a[i];
	ar[n] = num;
	delete[]a;
	n++;
	a = ar;
	return *this;	
}

Array& Array::add(int num, int in) {
	int* ar = new int[n + 1];
	for (int i = 0; i < in; i++) ar[i] = a[i];
	ar[in] = num;
	for (int i = in+1; i < n+1; i++) ar[i] = a[i-1];
	delete[]a;
	n++;
	a = ar;
	return *this;

}

Array& Array::del(int in) {
	if (in >= n) {
		cout << "Out of range" << endl;
		return *this;
	}

	int* ar = new int[n - 1];
	for (int i = 0; i < in; i++) ar[i] = a[i];
	for (int i = in + 1 ; i < n; i++) ar[i-1] = a[i];
	delete[]a;
	n--;
	a = ar;
	return *this;
}

Array& Array::del() {
	int* ar = new int[n - 1];
	for (int i = 0; i < n-1; i++) ar[i] = a[i];
	delete[]a;
	n--;
	a = ar;
	return *this;
}

Array& Array::clear() {
	delete[]a;
	n = 0;
	a = new int[n];
	return *this;
}

Array& Array::operator=(const Array& ar) {
	if (this == &ar) return *this;

	int* newArr = nullptr;
	if (ar.n > 0) {
		newArr = new int[ar.n];
		for (int i = 0; i < ar.n; i++) {
			newArr[i] = ar.a[i];
		}
	}
	delete[]a;
	a = newArr;
	n = ar.n;
	return *this;
}

ostream& operator<<(ostream& os, const Array& ar)
{
	for (int i = 0; i < ar.n; i++) os << ar.a[i] << " ";
	return os;
}
