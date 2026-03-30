#pragma once
#include <iostream>
#include <string>

class Clock {
private:
	int hours;
	int minutes;
public:
	Clock(int h = 0, int m = 0): hours(h), minutes(m) {}
	void virtual print(std::ostream&) const;
	void setTime(int h, int m);
	friend std::ostream& operator<<(std::ostream&, const Clock&);
};

class FitnessTracker {
private:
	int steps;
	int pulse;
public:
	FitnessTracker(int s = 0, int p = 0): steps(s), pulse(p) {}
	void virtual print(std::ostream&) const;
	void setInf(int s, int p);
	friend std::ostream& operator<<(std::ostream&, const FitnessTracker&);
};

class SmartWatch : public Clock, public FitnessTracker {
private:
	int battery;
	std::string name;
public:
	SmartWatch(int b = 0, std::string n = "", int h = 0, int m = 0, int s = 0, int p = 0) : Clock(h, m), FitnessTracker(s, p), battery(b), name(n) {}
	void print(std::ostream&) const override;
	void edit();
    friend std::ostream& operator<<(std::ostream&, const SmartWatch&);
};