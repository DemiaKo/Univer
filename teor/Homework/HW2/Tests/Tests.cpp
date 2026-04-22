#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../HW2/Algor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MarkovTests
{
    TEST_CLASS(MarkovTests)
    {
    public:

        TEST_METHOD(Test_To_Unary_Conversion)
        {
            // Перевіряємо, чи правильно генерується початкове слово
            Assert::AreEqual(string("||*|||"), to_un(2, 3));
            Assert::AreEqual(string("*||"), to_un(0, 2));
            Assert::AreEqual(string("||*"), to_un(2, 0));
            Assert::AreEqual(string("*"), to_un(0, 0));
        }

        TEST_METHOD(Test_Multiplication_Normal)
        {
            // Стандартні випадки множення
            // 2 * 3 = 6
            int n1 = 2, n2 = 3;
            string result1 = algo(n1, n2);
            Assert::AreEqual(string("||||||"), result1);

            // 4 * 2 = 8
            n1 = 4, n2 = 2;
            string result2 = algo(n1, n2);
            Assert::AreEqual(string("||||||||"), result2);
        }

        TEST_METHOD(Test_Multiplication_By_Zero)
        {
            // Крайові випадки: множення на нуль (має повернути порожній рядок)

            // 0 * 5 = 0
            string result1 = algo(0, 5);
            Assert::AreEqual(string(""), result1);

            // 5 * 0 = 0
            string result2 = algo(5, 0);
            Assert::AreEqual(string(""), result2);

            // 0 * 0 = 0
            string result3 = algo(0, 0);
            Assert::AreEqual(string(""), result3);
        }

        TEST_METHOD(Test_Multiplication_By_One)
        {
            // Множення на одиницю

            // 1 * 4 = 4
            string result1 = algo(1, 4);
            Assert::AreEqual(string("||||"), result1);

            // 3 * 1 = 3
            string result2 = algo(3, 1);
            Assert::AreEqual(string("|||"), result2);
        }
    };
}