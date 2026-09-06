#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Clock {
protected:
	std::string brand;
	std::string model;
public:
	Clock (std::string b = "", std::string m = ""): brand(b), model(m) {}
	friend int fromFile(std::ifstream&, Clock**&);
    virtual void print(std::ostream&) const;
    std::string getBrand() const;
	friend std::ostream& operator<< (std::ostream&, const Clock&);
	friend void Sort_model(Clock**, int);
	virtual ~Clock(){}
};

class Mech_Clock : public Clock {
private:
	int work_time;
	int varanty;
public:
	Mech_Clock(std::string b = "", std::string m = "", int w = 0, int v = 0): Clock(b, m), work_time(w), varanty(v) {}
	void print(std::ostream&) const override;
	friend Mech_Clock* search(Clock**, int);
};

Mech_Clock* search(Clock**, int);

void PrintByBrand(Clock** c, int n, std::string brand);
void PrintByBatType(Clock** c, int n, std::string bat_type);


class Ele_Clock : public Clock {
private:
	std::string bat_type;
	std::string scr_type;
public:
	Ele_Clock(std::string b = "", std::string m = "", std::string bt = "", std::string st = ""): Clock(b, m), bat_type(bt), scr_type(st) {}
	void print(std::ostream&)  const override;
    std::string getBatType() const;
};