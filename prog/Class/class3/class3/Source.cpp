#include <iostream>
#include <ctime>
#include <string>
using namespace std;

template <typename T> 

T sum(T a, T b) {
	return(a + b);
}

void print(int& a, int& b) {
	cin >> a >> b;
}

int main() {
	int a = 1, f = 2;
	print(a, f);
	cout << a << " " << f << endl;
	return(0);
}


/*int main() {
	srand(time(0));
	int n; cin >> n;
	int** m = new int*[n];
	int* v = new int[3*n-2];
	for (int i = 0; i < n; i++)
	{
		m[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = rand()%10;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		v[n-i-1] = m[n-1][i];
	}
	for (int i = 1; i < n; i++) {
		v[n - 1 + i] = m[n-i-1][i];
	}
	for (int i = n - 2; i >= 0; i--) {
		v[3*n-3-i] = m[0][i];
	}
	for (int i = 0; i < 3*n-2; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	
	return(0);
}*/

/*int main() {
	srand(time(0));
	int n = 10, min = 0;
	int* m = new int [n];
	for (int i = 0; i < n; i++) {
		m[i] = (rand() % 100) * pow((-1), rand()%10);
	}
	for (int i = 0; i < n; i++) {
		if (m[i] > 0) {
			min = m[i];
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if ((m[i] < min) && (m[i] > 0)) {
			min = m[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (m[i] < 0) {
			m[i] = min;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	return(0);
}
*/