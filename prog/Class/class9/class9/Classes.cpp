#include "Classes.h"

Student::Student(string s, int n, float f) {
	name = s;
	age = n;
	mark = f;
}

void Student::Output() const {
	cout << name << " " << age << " " << mark << endl;
}

Student& Student::Sort(Student& s)
{
	if (this->mark > s.mark) return *this;
	else return s;
}

bool Student::operator>(Student& s) const
{
	if (this->mark > s.mark) return true;
	else return false;
}
