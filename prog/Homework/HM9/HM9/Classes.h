#pragma once
#include <iostream>
#include <string>
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
private:
    string brand;
    Processor cpu;
    VideoCard gpu;

public:
    Computer(string b = "", Processor p = Processor("", 1, 1), VideoCard v = VideoCard("", 1)) : brand(b), cpu(p), gpu(v) {}
    void print(ostream&) const;
    void edit();
    friend ostream& operator<<(ostream&, Computer&);
};