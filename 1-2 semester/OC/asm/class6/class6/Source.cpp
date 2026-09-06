#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int n = 5;

const float c6 = 6.0f;
const float c12 = 12.0f;
const float c1 = 1.0f;

float c, d;
float a[n];
float res[n]; 

void calculateASM()
{
    __asm
    {
        lea esi, a   
        lea edi, res 
        mov ecx, n
        finit      
        iteration :     

        fld c6
            fmul c      
            fld c12
            fdiv d      
            fsqrt       
            fmul d     
            fsubp st(1), st(0) 

            fld[esi]    
            fadd c     
            fsub c1    

            fdivp st(1), st(0) 
            fstp[edi]  

            add esi, 4
            add edi, 4
            loop iteration 
    }
}

void enteringData()
{
    cout << " Input c : ";
    cin >> c;
    cout << " Input d : ";
    cin >> d;

    if (c <= d) {
        cout << " Warning: Condition c > d is not met!" << endl;
    }

    cout << " Input a[i] :" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << " a[" << i + 1 << "] = ";
        cin >> a[i];
    }
}

void printRes(string sym)
{
    cout << " Calculate in " << sym << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << " result: [" << i + 1 << "] = " << res[i] << endl;
    }
}

void calculateCpp()
{
    for (int i = 0; i < n; i++)
    {
        res[i] = (6 * c - d * sqrt(12 / d)) / (c + a[i] - 1);
    }
}

int main()
{
    enteringData();
    calculateASM();
    printRes("ASM");
    calculateCpp();
    printRes("C++");
    system("pause");
    return 0;
}