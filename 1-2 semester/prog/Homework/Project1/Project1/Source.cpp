#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x, y; cin >> x;
	if (x < 0) {
		y = x * x;
	}
	else {
		y = x;
	}
	cout << y << endl;

	system("pause");
	return 0;
}