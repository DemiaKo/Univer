#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int age;
	float mark;

public:
	Student(string = "", int = 0, float = 0);
	void Output() const;
	Student& Sort(Student& s);
	bool operator>(Student& s) const;
};

