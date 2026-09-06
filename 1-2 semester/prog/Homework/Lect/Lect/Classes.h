#pragma once
#include <iostream>
using namespace std;

class Shape {
protected:
	float area;
	float perim;
	virtual void Calc();
public:
	Shape(): area(0), perim(0) {}
	virtual void Print(ostream&) const;
	friend ostream& operator<<(ostream&, const Rect&);
	virtual ~Shape();
};

class Rect: public Shape {
protected:
	int a, b;
public:
	Rect(int = 1, int = 1);
    virtual void Print(ostream&) const;
	friend ostream& operator<<(ostream&, const Rect&);
	virtual ~Rect();
};

class Square : public Rect {
public:
	Square(int a = 1) : Rect(a, a) {};
	void virtual Print(ostream&) const;
};

class Circle : public Rect {
private:
	virtual void SetArePer(int, int) override;
public:
	Circle(int = 1);
	void virtual Print(ostream&) const;
};

class Trian : public Rect {
private:
	int c;
	void SetArePer(int, int, int);
public:
	Trian(int = 1, int = 1, int = 1);
	void virtual Print(ostream&) const;
};