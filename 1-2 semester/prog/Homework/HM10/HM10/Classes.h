#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Computer;

class Processor {
private:
    string model;
    int cores;
    double frequency;

public:
    Processor(string m, int c, double f) : model(m), cores(c), frequency(f) {}

    void print(ostream&) const;
    void edit();
    friend ostream& operator<<(ostream&, Processor&);
    friend Computer;
};

class VideoCard {
private:
    string model;
    int memory;

public:
    VideoCard(string m, int mem) : model(m), memory(mem) {}

    void print(ostream&) const;
    void edit();
    friend ostream& operator<<(ostream&, VideoCard&);
};

class Computer {
protected:
    string brand;
    Processor cpu;
    VideoCard gpu;

public:
    Computer(string b = "", Processor p = Processor("", 1, 1), VideoCard v = VideoCard("", 1)) : brand(b), cpu(p), gpu(v) {}
    virtual void print(ostream&) const;
    virtual void edit();
    friend ostream& operator<<(ostream&, Computer&);
    friend int fromFile(ifstream&, Computer**&);
    virtual ~Computer() {}
};

class Laptop: public Computer {
private:
	int battery;
public:
	Laptop(string b = "", Processor p = Processor("", 1, 1), VideoCard v = VideoCard("", 1), int ba = 1): Computer(b, p, v), battery(ba) {}
	void print(ostream&) const override;
    void edit() override;
};

class Desktop : public Computer {
private:
	string formFactor;
public:
	Desktop(string b = "", Processor p = Processor("", 1, 1), VideoCard v = VideoCard("", 1), string f = ""): Computer(b, p, v), formFactor(f) {}
	void print(ostream&) const override;
    void edit() override;
};