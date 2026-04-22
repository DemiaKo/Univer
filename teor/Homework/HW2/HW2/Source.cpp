#include "Algor.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int n1, n2;

    cout << "Введіть два числа через пробіл: ";
    cin >> n1 >> n2;

    algo(n1, n2);

    
    return 0;
}