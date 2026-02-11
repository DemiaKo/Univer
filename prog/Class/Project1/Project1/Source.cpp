#include <iostream>
using namespace std;

int main() {
	float Tab[30];
	for (int n = 0; n < 30; n++) Tab[n] = rand() % 100;
	float min = Tab[0];
	float min_ind = 0;
	for (int n = 1; n < 30; n++) {
		if (Tab[n] < min) {
			min = Tab[n];
			min_ind = n;
		}
	}
	cout << min << " " << min_ind <<  endl;
	printf("dwqdsadqwdsdasdvdvfdfv ")
}