#include <cmath>
#include <stdio.h>	

void func(int* T ) {
	for (int i = 0; i < 4; i++) {
		printf("%d ", *(T+3-i));
	}
}

int main() {
	int* Tab = new int[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d", &Tab[i]);
	}
	func(Tab);
}