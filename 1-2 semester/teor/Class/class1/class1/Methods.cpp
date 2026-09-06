#include "Methods.h"

bool Method_1(int n) {
	bool s = true;
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) s = false;
	}
	return(s);
}

bool Method_2(int n, int i) {
	if (n <= 2) return (n == 2);
	if (n % i == 0) return false;
	if (i * i > n) return true;

	return Method_2(n, ++i);
}

bool Method_3(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}