#include <iostream>
using namespace std;

/*int max(int n1, int n2, int n3) {
	int m = 0;
	if (n1 <= n2) m = n1;
	else m = n2;
	if (m <= n3) m = n3;
	return (m);
}

int mian() {
	int a, b, c; cin >> a >> b >> c;
	cout << max(a, b, c) << endl;
}*/

/*bool x(int f) {
	if (f <= 1) return true;
	for (int i = 2; i < f - 1; i++) {
		if (f % i == 0) return true;
	}
	return false;
}

int main() {
	int n; cin >> n;
	if (x(n)) cout << "not";
	else cout << "ja";
}*/

float S(float a) {
	return (a * a);
}
float S(float a, float b) {
	return(a * b);
}
float S(float a, float b, float c) {
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

int main() {
	float a, b, c; cin >> a >> b >> c;
	cout << S(a) << endl;
	cout << S(a, b) << endl;
	cout << S(a, b, c) << endl;
}