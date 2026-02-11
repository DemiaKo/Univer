#include "Structures.h"

template <typename T>

void input(T &m) {
	float a, b, c, d;
	cin >> a >> b >> c >> d;
	m = T{a, b, c, d};
}

int main() {
	Metric s(0, 1, 1, 1), h(10, 99, 999, 1), k = s + h, p;
	Imperial f(0, 32, 124, 2), g(43, 1, 53, 66), l = f + g, o;
	
	k.Print();
	l.Print();
	p = l.To_Metric();
	o = k.To_Imperial();
	p.Print();
	o.Print();
	
	return 0;
}