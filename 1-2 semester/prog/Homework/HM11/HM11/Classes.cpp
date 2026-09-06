#include "Classes.h"

std::ostream& operator<<(std::ostream& os, const Clock& c) {
	c.print(os);
	return(os);
}

std::ostream& operator<<(std::ostream& os, const FitnessTracker& f) {
	f.print(os);
	return(os);
}

std::ostream& operator<<(std::ostream& os, const SmartWatch& s) {
	s.print(os);
	return os;
}

void Clock::print(std::ostream& os) const {
	os << "Hours: " << hours << ", minutes: " << minutes << std::endl;
}

void Clock::setTime(int h, int m) {
	hours = h;
	minutes = m;
}

void FitnessTracker::print(std::ostream& os) const {
	os << "Steps: " << steps << ", pulse: " << pulse << std::endl;
}

void FitnessTracker::setInf(int s, int p) {
	steps = s;
	pulse = p;
}

void SmartWatch::print(std::ostream& os) const {
	os << "Battery: " << battery << ", brand: " << name << std::endl;

	Clock::print(os);
	FitnessTracker::print(os);
}

void SmartWatch::edit() {
	int h, m, s, p, b;
	std::string n;
	std::cin >> h >> m >> s >> p >> b;
	std::getline(std::cin >> std::ws, n);
	Clock::setTime(h, m);
	FitnessTracker::setInf(s, p);
	battery = b;
	name = n;
}
