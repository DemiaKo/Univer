#include "pch.h"
#include "CppUnitTest.h"
#include "../HW5/Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTests
{
	TEST_CLASS(CalculatorTests)
	{
	public:

		TEST_METHOD(TestBasicArithmetic)
		{
			std::string expr = "2 + 3";
			std::string expected_rpn = "2 3 + ";

			Assert::IsTrue(expected_rpn == to_pol(expr));
			Assert::AreEqual((double)5, calc(expected_rpn));
		}

		TEST_METHOD(TestOperatorPrecedence)
		{
			std::string expr = "2 + 3 * 4";
			std::string expected_rpn = "2 3 4 * + ";

			Assert::IsTrue(expected_rpn == to_pol(expr));
			Assert::AreEqual((double)14, calc(expected_rpn));
		}

		TEST_METHOD(TestParentheses)
		{
			std::string expr = "(2 + 3) * 4";
			std::string expected_rpn = "2 3 + 4 * ";

			Assert::IsTrue(expected_rpn == to_pol(expr));
			Assert::AreEqual((double)20, calc(expected_rpn));
		}

		TEST_METHOD(TestMultiDigitNumbers)
		{
			std::string expr = "150 / 10 + 25";
			std::string expected_rpn = "150 10 / 25 + ";

			Assert::IsTrue(expected_rpn == to_pol(expr));
			Assert::AreEqual((double)40, calc(expected_rpn));
		}

		TEST_METHOD(TestExponentiation)
		{
			std::string expr = "3 ^ 2 + 1";
			std::string expected_rpn = "3 2 ^ 1 + ";

			Assert::IsTrue(expected_rpn == to_pol(expr));
			Assert::AreEqual((double)10, calc(expected_rpn));
		}

		TEST_METHOD(TestDivisionByZeroException)
		{
			std::string expr = "5 / (2 - 2)";
			std::string rpn = to_pol(expr);

			auto func = [&] { calc(rpn); };

			Assert::ExpectException<std::runtime_error>(func);
		}
	};
}