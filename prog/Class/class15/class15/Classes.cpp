#include "Classes.h"
#include <algorithm>

void rtrim(std::string &s) {
	while (!s.empty()) {
		char ch = s.back();
		if (ch == ' ')
			s.pop_back();
		else
			break;
	}
}

int fromFile(std::ifstream& f, Clock**& c) {
	int n; f >> n;
	c = new Clock * [n];
	for (int i = 0; i < n; i++) {
		char T; f >> T;

		switch (T) {
        case 'M': {
			std::string br, mo;
			int wo, va;
			std::getline(f >> std::ws, br, '|');
			std::getline(f >> std::ws, mo, '|');
			rtrim(br);
			rtrim(mo);
			f >> wo >> va;
			c[i] = new Mech_Clock(br, mo, wo, va);
			break;
		}
        case 'E': {
			std::string br, mo, bt, st;
			std::getline(f >> std::ws, br, '|');
			std::getline(f >> std::ws, mo, '|');
			std::getline(f >> std::ws, bt, '|');
			std::getline(f >> std::ws, st);
			rtrim(br);
			rtrim(mo);
			rtrim(bt);
			rtrim(st);
			c[i] = new Ele_Clock(br, mo, bt, st);
			break;
		}
		default:
			c[i] = nullptr;
			break;
		}
	}
	return n;
}

std::ostream& operator<<(std::ostream& os, const Clock& c) {
	c.print(os);
	return(os);
}

std::string Clock::getBrand() const { return brand; }

void PrintByBrand(Clock** c, int n, std::string brand) {
	for (int i = 0; i < n; ++i) {
		if (c[i]->getBrand() == brand) std::cout << *c[i] << std::endl;
	}
}

void PrintByBatType(Clock** c, int n, std::string bat_type) {
	for (int i = 0; i < n; ++i) {
        if (auto e = dynamic_cast<Ele_Clock*>(c[i])) {
			if (e->getBatType() == bat_type) std::cout << *e << std::endl;
		}
	}
}

void Sort_model(Clock** c, int n) {

	std::sort(c, c + n, [](Clock* a, Clock* b) {
		if (!a) return false;
		if (!b) return true;
		return a->model < b->model;
	});
}

Mech_Clock* search(Clock** c, int n) {
	Mech_Clock* best = nullptr;
	for (int i = 0; i < n; ++i) {
		if (!c[i]) continue;
		if (auto m = dynamic_cast<Mech_Clock*>(c[i])) {
			if (!best || m->varanty < best->varanty) best = m;
		}
	}
	return best;
}

void Clock::print(std::ostream& os) const {
	os << brand << ", " << model;
}

void Mech_Clock::print(std::ostream& os) const {
	os << "Mech_Clock: ";
	Clock::print(os);
	os << ", " << work_time << ", " << varanty << std::endl;
}

void Ele_Clock::print(std::ostream& os) const {
	os << "Ele_Clock: ";
	Clock::print(os);
	os << ", " << bat_type << ", " << scr_type << std::endl;
}

std::string Ele_Clock::getBatType() const { return bat_type; }
