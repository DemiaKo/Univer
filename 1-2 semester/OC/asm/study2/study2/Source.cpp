#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	float p, a, aa;
	int n; 
	char FF[] = "%.2f\n";
	cin >> a >> p >> n;

	__asm {
		movss xmm0, p
		mov eax, 100
		cvtsi2ss xmm1, eax
		divss xmm0, xmm1
		mov eax, 1
		cvtsi2ss xmm1, eax
		addss xmm0, xmm1
		movss xmm1, xmm0
		mov eax, 1
		cvtsi2ss xmm0, eax
		mov ecx, n
		l:
		mulss xmm0, xmm1
		loop l
		movss xmm1, a
		mulss xmm0, xmm1
		cvtss2sd xmm0, xmm0
		sub esp, 8
		movsd qword ptr [esp], xmm0
		lea eax, FF
		push eax
		call printf
		add esp, 12
	}


	return(0);
}