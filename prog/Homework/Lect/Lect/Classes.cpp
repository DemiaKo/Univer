#include "Classes.h"

void Rect::SetArePer(int a, int b) {
	perim = (2 * a) + (2 * b);
	area = a * b;
}

Rect::Rect(int a, int b) {
	if (a <= 0 || b <= 0) {
		cout << "Its not a rect..." << endl;
	}
	else {
		this->a = a;
		this->b = b;
	}
	SetArePer(a, b);
}

void Rect::Print(ostream& os) const {
	os << "Rectangle: a = " << a << " b = " << b << " area = " << area << " perimeter = " << perim << endl;
}

ostream& operator<<(ostream& os, const Rect& rec) {
	rec.Print(os);
	return os;
}

void Square::Print(ostream& os) const {
	os << "Square: a = " << a << " area = " << area << " perimeter = " << perim << endl;
}

void Circle::SetArePer(int a, int b) {
	perim = 2 * a * 3.14;
	area = 3.14 * pow(a, 2);
}

Circle::Circle(int r) {
	if (a <= 0) {
		cout << "Its not a circle" << endl;
	} else a = r;
	SetArePer(r, r);
}

void Circle::Print(ostream& os) const {
	os << "Circle: r = " << a << " area = " << area << " perimeter = " << perim << endl;
}

void Trian::SetArePer(int a, int b, int c) {
	perim = a + b + c;
	float p = perim / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
}

Trian::Trian(int a, int b, int c) {
	if (a + b <= c || b + c <= a || a + c <= b) {
		cout << "Its not a triangle" << endl;
		this->a = 1;
		this->b = 1;
		this->c = 1;
	}
	else {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	SetArePer(this->a, this->b, this->c);
}

void Trian::Print(ostream& os) const {
	os << "Triangle: a = " << a << " b = " << b << " c = " << c << " area = " << area << " perimeter = " << perim << endl;
}