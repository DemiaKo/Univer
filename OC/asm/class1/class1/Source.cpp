#include <iostream>
using namespace std;

// Формат рядка для printf: три рядкові параметри і одне числове
char FORMAT[] = "%s %s %s, %d\n";
char Designed[] = "Designed";
char By[] = "by";
char Demian[] = "Demian";
int Year = 2026;

int main() {
	__asm {
		// Спочатку поміщаємо значення Year в EAX і штовхаємо його на стек
		// (це буде параметр для %d у форматі)
		mov eax, dword ptr[Year]
		push eax

		// Далі штовхаємо адреси рядків: порядок push робить так, що
		// останній push (FORMAT) стає першим параметром функції printf.
		mov eax, offset Demian
		push eax            // третій %s
		mov eax, offset By
		push eax            // другий %s
		mov eax, offset Designed
		push eax            // перший %s
		mov eax, offset FORMAT
		push eax            // форматний рядок

		// Виклик printf: переміщаємо адресу в EDI і викликаємо через call
		mov edi, printf
		call edi

		// Тут просте очищення через 5 pop
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
	}

	return(0);
}
