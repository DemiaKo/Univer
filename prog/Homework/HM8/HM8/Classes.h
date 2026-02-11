#pragma once
#include <iostream>

using namespace std;

class Time {
private:
	int s, m, h;
public:
	Time(int = 0, int = 0, int = 0);
	Time operator+(const Time) const;
	friend ostream& operator<<(ostream&, const Time&);
};
