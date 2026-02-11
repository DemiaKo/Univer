#pragma once
#include <iostream>
using namespace std;

class Vector {
private:
	int x, y;
public:
	Vector(int = 0, int = 0);
	Vector operator+(const Vector&)const;
	Vector operator-(const Vector&)const;
	int operator*(const Vector&)const;
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
};