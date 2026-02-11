#pragma once
#include <iostream>
using namespace std;

struct Imperial;

struct Metric {
	float mm, cm, m, km;

	Metric();
	Metric(float, float, float, float);
	void Print();
	Metric operator+(Metric);
	Imperial To_Imperial();
};

struct Imperial {
	float in, ft, yd, mi;

	Imperial();
	Imperial(float, float, float, float);
	void Print();
	Imperial operator+(Imperial);
	Metric To_Metric();
};