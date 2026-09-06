#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tovar{
private:
	string name;
	int code;
	float price;
public:
	Tovar();
	string Get_name();
	int Get_code();
	float Get_price();
	friend ostream& operator<<(ostream&, const Tovar&);
	friend istream& operator>>(istream&, Tovar&);
	friend Tovar& max(Tovar*, int);
	friend Tovar& min(Tovar*, string, int);
	~Tovar();
};
