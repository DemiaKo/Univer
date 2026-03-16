#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class Table {
private:
	float* ar;
	int rows, cols; 
	class Tb {
	private:
		float* a;
		int ro, co;
	public:
		Tb(float* aa, int r, int c) : ro(r), a(aa), co(c) {}
		float& operator[](int);
	};
public:
	Table(int r = 2, int c = 2) : rows(r), cols(c) { if (r <= 0 || c <= 0) throw std::invalid_argument("Negative or zero argum"); 
		ar = new float[rows * cols]; this->clear(); }
	Table(const Table&);
	Tb operator[](int);
	void clear();
	void print(std::ostream&) const;
	void input(std::istream&);
	void resize(int r, int c);
	std::string search(float) const;
	Table& operator=(const Table&);
	~Table() { delete[] ar; }
};

std::ostream& operator<<(std::ostream&, const Table&);
std::istream& operator>>(std::istream&, Table&);