#include "Structures.h"

Metric::Metric(float smm = 0, float scm = 0, float sm = 0, float skm = 0) {
	mm = smm;
	cm = scm;
	m = sm;
	km = skm;
	if (mm >= 10) {
		cm += mm / 10;
		mm = (int)mm%10;
	}
	if (cm >= 100) {
		m += cm / 100;
		cm = (int)cm%100;
	}
	if (m >= 1000) {
		km += m / 1000;
		m = (int)m%1000;
	}
}

Metric::Metric() {
	mm = 0;
	cm = 0;
	m = 0;
	km = 0;
	if (mm >= 10) {
		cm += mm / 10;
		mm = (int)mm % 10;
	}
	if (cm >= 100) {
		m += cm / 100;
		cm = (int)cm % 100;
	}
	if (m >= 1000) {
		km += m / 1000;
		m = (int)m % 1000;
	}
}

void Metric::Print() {
	cout << "Milimeters: " << mm << " Centyneters: " << cm << " Meters: " << m << " Kilometers: " << km << endl;
}

Metric Metric::operator+(Metric met) {
	mm += met.mm;
	cm += met.cm;
	m += met.m;
	km += met.km;
	return Metric(mm, cm, m, km);
}

Imperial Metric::To_Imperial() {
	float in = mm * 0.0393701;
	float ft = cm * 0.0328084;
	float yd = m * 1.09361;
	float mi = km * 0.621371;
	return Imperial(in, ft, yd, mi);
}

Imperial::Imperial(float sin = 0, float sft = 0, float syd = 0, float smi = 0) {
	in = sin;
	ft = sft;
	yd = syd;
	mi = smi;
	if (in >= 12) {
		ft += in / 12;
		in = (int)in%12;
	}
	if (ft >= 3) {
		yd += ft / 3;
		ft = (int)ft%3;
	}
	if (yd >= 1760) {
		mi += yd / 1760;
		yd = (int)yd%1760;
	}
}

Imperial::Imperial() {
	in = 0;
	ft = 0;
	yd = 0;
	mi = 0;
	if (in >= 12) {
		ft += in / 12;
		in = (int)in % 12;
	}
	if (ft >= 3) {
		yd += ft / 3;
		ft = (int)ft % 3;
	}
	if (yd >= 1760) {
		mi += yd / 1760;
		yd = (int)yd % 1760;
	}
}


void Imperial::Print() {
	cout << "Inches: " << in << " Foots: " << ft << " Yards: " << yd << " Miles: " << mi << endl;
}

Imperial Imperial::operator+(Imperial im) {
	in += im.in;
	ft += im.ft;
	yd += im.yd;
	mi += im.mi;
	return Imperial(in, ft, yd, mi);
}

Metric Imperial::To_Metric() {
	float mm = in * 25.4;
	float cm = ft * 30.48;
	float m = yd * 0.9144;
	float km = mi * 1.60934;
	return Metric(mm, cm, m, km);
}