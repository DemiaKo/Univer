#pragma once
#include <iostream>
using namespace std;

class Array {
private:
	int* a;
	int n;

public:
	Array();
	Array(const Array&);
	Array(int);
	Array(int*, int);
	int operator[](int);
	~Array();
	Array& add(int);
	Array& add(int, int);
	Array& del(int);
	Array& del();
	Array& clear();
	Array& operator=(const Array&);
	friend ostream& operator<<(ostream&, const Array&);
};