#include "Structures.h"

Student Max(const Student* s, int n) {
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (s[max].av_mark < s[i].av_mark) {
			max = i;
		}
	}
	return(s[max]);
}

int main() {
	ofstream fout("txt.txt");
	int n; cin >> n;
	Worker* w = new Worker[n];
	for (int i = 0; i < n; i++) {
		w[i].Input();
	}
	for (int i = 0; i < n; i++) {
		if (w[i].years >= 5) {
			fout << w[i].name << " " << w[i].job << " " << w[i].salary << " " << w[i].years << endl;
		}
	}

	return(0);
}