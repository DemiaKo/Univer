#include <iostream>
using namespace std;

int main() {
	int n = 123, res, ress;
	cin >> n;

	__asm {
		mov eax, n
		mul eax
		mov ecx, eax
		mov eax, n
		mov ebx, 10
		cdq
		div ebx
		push edx
		cdq
		div ebx
		add eax, edx
		pop edx
		add eax, edx
		push eax
		mul eax
		pop edx
		mul edx
		mov res, eax
		mov ress, ecx
	}

	cout << res << " " << ress << sizeof(int) << endl;

	return(0);
}