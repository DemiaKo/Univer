#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	/*const int n = 10;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n-1; i++) {
		if (ar[i] > ar[i + 1]) {
			int x = ar[i];
			ar[i] = ar[i + 1];
			ar[i + 1] = x;
			i = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}
	cout << endl;*/

	/*const int n = 10;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int max = 0, min = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] < ar[min]) {
			min = i;
		}
		if (ar[i] > ar[max]) {
			max = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i > max || i > min) {
			sum += ar[i];
			if (i + 1 == max || i + 1 == min) {
				break;
			}
		}
	}
	cout << sum << endl;*/

	/*const int n = 10;
	int ar[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 1; i < n; i += 2) {
		for (int j = 0; j < n; j++) {
			ar[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}*/
	const int n = 10;
	int ar[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ar[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			ar[n - i - 1][j] = ar[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

	return(0);
}