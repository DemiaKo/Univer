#pragma once

struct raci {
	int verh;
	int nyz;
	raci(int v = 1, int n = 1): verh(v), nyz(n) {}
	raci(raci& other): verh(other.verh), nyz(other.nyz) {}
	raci& operator=(raci& other) { if (this == &other) { return *this; } this->nyz = other.nyz; this->verh = other.verh; return *this; }
	bool operator<(raci& other) { return (this->verh) * other.nyz < (other.verh) * this->nyz; }
	bool operator>(raci& other) { return (this->verh) * other.nyz > (other.verh) * this->nyz; }
	bool operator==(raci& other) { return (this->verh) * other.nyz == (other.verh) * this->nyz; }
	bool operator<=(raci& other) { return (this->verh) * other.nyz <= (other.verh) * this->nyz; }
	bool operator>=(raci& other) { return (this->verh) * other.nyz >= (other.verh) * this->nyz; }

};