#include "Classes.h"

Tovar::Tovar() {
	name = "";
	code = 0;
	price = 0;
}

string Tovar::Get_name()
{
	return name;
}

int Tovar::Get_code()
{
	return code;
}

float Tovar::Get_price()
{
	return price;
}

Tovar::~Tovar()
{
}

ostream& operator<<(ostream& os, const Tovar& t) {
	os << t.name << " " << t.code << " " << t.price << " ";
	return os;
}

istream& operator>>(istream& is, Tovar& t) {
	is >> t.name >> t.code >> t.price;
	return is;
}

Tovar& max(Tovar* t, int n)
{
	int m = 0;
	for (int i = 1; i < n; i++) {
		if (t[m].Get_price() < t[i].Get_price()) {
			m = i;
		}
	}
	return t[m];
}

Tovar& min(Tovar* t, string s, int n)
{
	int m;
	int i = 0;
	while (true) {
		if (i == n) {
			cout << "Nema takogo!" << endl;
			return t[0];
		}
		if (t[i].Get_name() == s) {
			m = i;
			break;
		}
		i++;
	}
	for (int i = 0; i < n; i++) {
		if (t[m].Get_price() > t[i].Get_price() && t[i].Get_name() == s) {
			m = i;
		}
	}
	return t[m];
}
