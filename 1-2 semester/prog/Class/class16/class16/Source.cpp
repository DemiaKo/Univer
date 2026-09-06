#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
	string name;
	int age;
public:
	Human(string n, int a): name(n), age(a) { cout << "Human c" << endl; }
	~Human() { cout << "Human d" << endl; }
};

class Employee: public virtual Human{
protected:
	string posada;
	int wage;
public:
	Employee(string p = "", int w = 0, string n = "", int a = 0) : posada(p), wage(w), Human(n, a) { cout << "Employee c" << endl; }
	~Employee() { cout << "Employee d" << endl; }
};

class Pensioner : public virtual Human {
protected:
	float pensiya;
public:
	Pensioner(float p = 0, string n = "", int a = 0): Human(n, a), pensiya(p) {}
};

class Teacher : public Employee, public Pensioner {
private:
	string discipline;
public:
	Teacher(float pp = 0, string p = "", int w = 0, string d = "") : Pensioner(pp), Employee(p, w), discipline(d) {}
};

int main() {

	return(0);
}