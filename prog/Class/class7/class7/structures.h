#define _USE_MATH_DEFINES
#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Student {
	int age, group;
	float mark;
	string name;

	Student();
	void input();
	void output();
};

struct Time {
	int h, m, s;

	Time();
	Time(int, int, int);
	Time operator+(const Time&);
	void Input();
	void Output();
};

struct Polar {
	float dis, ang;

	Polar();
	Polar(float, float);
	void Output();
};

struct Decart {
	float x, y;

	Decart(float, float);
	Decart();
	Polar toPolar();
};