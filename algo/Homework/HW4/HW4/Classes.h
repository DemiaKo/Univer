#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

struct Cell
{
	std::string key = "";
	int value = 0;
	Cell* next = nullptr;
};

class Table {
private:
	int size;
	int real_size;
	Cell** cells;
	int hash(std::string) const;
	void resize();
public:
    Table(int s = 5) : size(s), real_size(0) { cells = new Cell * [size]; for (int i = 0; i < size; ++i) cells[i] = nullptr; }
	Table(const Table&);
	Table& operator=(const Table&);
	void insert(std::string, int);
	int get(std::string) const;
	void remove(std::string);
	int& operator[](std::string);
	void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const Table&);
	~Table();
};