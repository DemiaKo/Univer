#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int n;
	cout << "Введіть n: ";
	cin >> n;
	int** a = new int* [n];
	int** b = new int* [n];
	int** res = new int* [n];
	cout << "Введіть елементи матриці А: ";
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		b[i] = new int[n];
		res[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = i + j - 1;
			res[i][j] = 0;
		}
	}
	cout << "A : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cout << a[i][j] << " "; }
			cout << endl;
	}

	cout << endl;
	cout << "B : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	__asm {
		mov ecx, 0
		start1:
		mov edi, 0
	start2:
		mov edx, res
		mov esi, ecx
		imul esi, 4
		add edx, esi
		push[edx]
		pop edx
		mov esi, edi
		imul esi, 4
		add edx, esi
		push edx
		xor esi, esi
	start:
		mov eax, a
		mov ebx, b
	a_to_eax:
		mov edx, ecx
		mov eax, [eax + 4 * edx]
		mov edx, esi
		mov eax, [eax + 4 * edx]
	b_to_ebx:
		mov edx, esi
		mov ebx, [ebx + 4 * edx]
		mov edx, edi
		mov ebx, [ebx + 4 * edx]
	end:
		pop edx
		imul eax, ebx
		add[edx], eax
		push edx
		inc esi
		cmp esi, n
		jne start
		pop edx
		inc edi
		cmp edi, n
		jne start2
		inc ecx
		cmp ecx, n
		jne start1
	}

	cout << "A * B: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return(0);
}