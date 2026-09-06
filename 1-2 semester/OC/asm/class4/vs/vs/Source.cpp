#include <iostream>
using namespace std;

int main() {
	int arr = 848843586;
	int res = 0;

	__asm {
		mov cx, 8
		mov eax, 1

	start_outer:
		mov bx, 4
		xor di, di

	start_inner:
		mov edx, arr
		and edx, eax
		jz go_next
		inc di

	go_next:
		shl eax, 1
		dec bx
		test bx, bx
		jnz start_inner
		and di, 1
		jnp end_
		inc res

	end_:
		loop start_outer
	}

	cout << res << endl;
	return(0);
}