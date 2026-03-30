#include "pch.h"
#include "CppUnitTest.h"
#include "../HW6/Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparseMatrixTests
{
	TEST_CLASS(SparseMatrixTests)
	{
	public:

		TEST_METHOD(Test_Initialization_And_Default_Values)
		{
			SparseMatrix<int> m(2, 2);
			Assert::AreEqual(0, m.get(0, 0));
			Assert::AreEqual(0, m.get(1, 1));
		}

		TEST_METHOD(Test_Set_And_Get_Values)
		{
			SparseMatrix<int> m(3, 3);
			m.set(1, 1, 42);
			m.set(0, 2, 10);

			Assert::AreEqual(42, m.get(1, 1));
			Assert::AreEqual(10, m.get(0, 2));
			Assert::AreEqual(0, m.get(0, 0));
		}

		TEST_METHOD(Test_Proxy_Operators)
		{
			SparseMatrix<int> m(2, 2);
			m[0][1] = 99;
			int val = m[0][1];

			Assert::AreEqual(99, val);
		}

		TEST_METHOD(Test_Deep_Copy_Constructor)
		{
			SparseMatrix<int> original(2, 2);
			original[0][0] = 5;

			SparseMatrix<int> copy = original;
			copy[0][0] = 10;

			Assert::AreEqual(5, (int)original[0][0]);
			Assert::AreEqual(10, (int)copy[0][0]);
		}

		TEST_METHOD(Test_Deep_Assignment_Operator)
		{
			SparseMatrix<int> m1(2, 2);
			SparseMatrix<int> m2(3, 3);

			m1[1][1] = 7;
			m2 = m1;

			m2[1][1] = 14;

			Assert::AreEqual(7, (int)m1[1][1]);
			Assert::AreEqual(14, (int)m2[1][1]);
		}

		TEST_METHOD(Test_Exception_Out_Of_Bounds)
		{
			SparseMatrix<int> m(2, 2);
			auto func = [&] { m.get(5, 5); };
			Assert::ExpectException<std::out_of_range>(func);

			auto func2 = [&] { m[-1][0] = 10; };
			Assert::ExpectException<std::out_of_range>(func2);
		}

		TEST_METHOD(Test_Exception_Invalid_Dimensions)
		{
			auto func = [&] { SparseMatrix<int> m(0, 5); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}