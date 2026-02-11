#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
	string name;
	int age;
	double av_mark;

	void Input();
	void Output() const;

};

struct  Worker {
	string name;
	string job;
	float salary;
	float years;

	void Input();
};