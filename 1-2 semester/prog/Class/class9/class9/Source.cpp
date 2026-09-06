#include "Classes.h"

Student& Max(Student* s, int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] > s[max]) {
			max = i;
		}
	}
	return s[max];
}

int main() {
    Student* st = new Student[5];
    st[0] = Student("f", 1, 1);
	st
}