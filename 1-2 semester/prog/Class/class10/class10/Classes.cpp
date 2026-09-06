#include "Classes.h"

Vector::Vector(int a, int b) {
	x = a;
	y = b;
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y);
}

int Vector::operator*(const Vector& v) const
{
	return (x * v.x + y * v.y);
}

ostream& operator<<(ostream& os, const Vector& v) {
	os << v.x << " " << v.y;
	return os;
}

istream& operator>>(istream& is, Vector& v)
{
	is >> v.x >> v.y;
	return is;
}
