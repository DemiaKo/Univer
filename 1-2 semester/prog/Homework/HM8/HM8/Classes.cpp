#include "Classes.h"

Time::Time(int ss = 0, int mm = 0, int hh = 0) {
	s = ss;
	m = mm;
	h = hh;
	if (s >= 60) {
		m += s / 60;
		s %= 60;
	}
	if (m >= 60) {
		h += m / 60;
		m %= 60;
	}
}

Time Time::operator+(const Time t) const
{
	return Time(s + t.s, m+t.m, h+t.h);
}

ostream& operator<<(ostream& c, const Time& t)
{
	c << t.s << " " << t.m << " " << t.h << endl;
	return c;
}
