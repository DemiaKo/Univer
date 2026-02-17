#pragma once
#include <iostream>	
using namespace std;

class f;

class b {
private:
	int a;
public:
	static int n;
	b() : a(0) {}
	void c(f&);
};

class f {
private:
	int b;
public:
	f() : b(2) {}
	friend void b::c(f&);
};