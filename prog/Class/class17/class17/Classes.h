#pragma once

class Curve {
protected:
	double a;
	double b;
public:
	Curve(double a, double b): a(a), b(b) {}
    virtual double calc_y(double) const abstract;
	virtual ~Curve(){}
};

class Line : public Curve {
public:
	Line(double a, double b): Curve(a, b) {}
	double calc_y(double) const override;
};

class Elips : public Curve {
public:
	Elips(double a, double b) : Curve(a, b) {}
	double calc_y(double) const override;
};

class Hyperbola : public Curve {
public:
	Hyperbola(double a, double b) : Curve(a, b) {}
	double calc_y(double) const override;
};