#include "structures.h"

Student::Student() {
	age = 0;
	group = 0;
	mark = 0;
	name = "";
}

void Student::input() {
	cout << "Age: ";
	cin >> age;
	cout << "Group: ";
	cin >> group;
	cout << "Mark: ";
	cin >> mark;
	cout << "Name: ";
	cin >> name;
}

void Student::output() {
	cout << "Age:" << age << " mark: " << mark << " group: " << group << " name: " << name << endl;
}

Time::Time() {
	h = 0;
	m = 0;
	s = 0;
}

Time::Time(int _h, int _m, int _s) {
	h = _h;
	m = _m;
	s = _s;
}

Time Time::operator+(const Time& x) {
	int _h = x.h + h;
	int _m = x.m + m;
	int _s = x.s + s;
	if (_s >= 60) {
		_m += _s / 60;
		_s %= 60;
	}
	if (_m >= 60) {
		_h += _m / 60;
		_m %= 60;
	}
	return Time(_h, _m , _s);
}

void Time::Input() {
	cout << "H: ";
	cin >> h;
	cout << "M: ";
	cin >> m;
	cout << "S: ";
	cin >> s;
}

void Time::Output() {
	cout << "H: " << h << " m: " << m << " s: " << s;
}

Decart::Decart() {
	x = 0;
	y = 0;
}

Decart::Decart(float a, float b){
	x = a;
	y = b;
}

Polar Decart::toPolar() {
	float d = sqrt(x*x+y*y);
	float a = atan2(y, x);
	a = a * (180 / M_PI);
	return Polar(d, a);
}

Polar::Polar() {
	dis = 0;
	ang = 0;
}

Polar::Polar(float a, float b) {
	dis = a;
	ang = b;
}

void Polar::Output() {
	cout << "Dist: " << dis << " ang: " << ang << endl;
}