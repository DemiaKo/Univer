#include <iostream>
using namespace std;

int main() {

	int year, leap;
	cin >> year;
	__asm {
		// Ініціалізація: ebx = 0 (припустимо не високосний), ecx = 400
		mov ebx, 0
		mov ecx, 400

		// Ділимо year на 400: якщо остача (edx) = 0 -> високосний
		mov eax, year
		cdq
		div ecx
		test edx, edx
		jz is_leap

		// Перевірка ділення на 4 (основна умова для високосного)
		mov eax, year
		cdq
		mov ecx, 4
		div ecx
		test edx, edx
		jz maybe_leap
		jmp result

		// Мітка: рік ділиться на 400 -> позначити як високосний
		is_leap :
		mov ebx, 1
		jmp result

		// Мітка: рік ділиться на 4, але потрібно перевірити на 100
			maybe_leap :
		mov eax, year
			cdq
			mov ecx, 100
			div ecx
			test edx, edx
			jz result    // якщо ділиться на 100 -> не високосний
			jmp is_leap  // інакше -> високосний

			result :
		mov leap, ebx
	}

	if (leap > 0) { 
		cout << "Yes" << endl; 
	} else { 
		cout << "No" << endl; 
	}

    // Простий приклад: переставлення першої і останньої цифри трицифрового числа
	int num, result; cin >> num;

	__asm {
		// Завантажуємо в eax значення num
		mov eax, num

		// Ділимо на 100: результат у eax (сотні), остача в edx (двозначна частина)
		mov ebx, 100
		cdq
		div ebx

		// Зберігаємо сотні в ecx
		mov ecx, eax

		// Тепер в eax покладемо остачу (двозначну частину)
		mov eax, edx

		// Ділимо двозначну частину на 10: отримуємо десятки в eax, одиниці в edx
		mov ebx, 10
		cdq
		div ebx

		// edx = одиниці (останній розряд) -> зберігаємо на стек
		push edx

		// eax зараз = десятки; множимо на 10 щоб отримати їх внесок у середню позицію
		mov ebx, 10
		mul ebx
		// Додаємо до ecx (сотні) значення десятків*10
		add ecx, eax

		// Відновлюємо одиниці з стеку в eax
		pop eax
		// Множимо одиниці на 100 щоб перенести їх в позицію сотень
		mov ebx, 100
		mul ebx

		// Додаємо отримані сотні (з колишніх одиниць) до накопиченого значення
		add eax, ecx

		// Зберігаємо кінцевий результат у змінну result
		mov result, eax
	}
	// Виводимо результат: число з переставленими першою та останньою цифрою
	cout << result << endl;

	return(0);
}
