#include <iostream>
using namespace std;

int main() {

	int a = 10;
	int* p = &a;
	int** pp = &p;
	int*** ppp = &pp;
	cout << *ppp << endl;
	cout << **ppp << endl;
	cout << ***ppp << endl;

	return 0;
}