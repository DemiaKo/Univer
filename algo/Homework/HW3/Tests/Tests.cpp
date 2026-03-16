#include "pch.h"
#include "CppUnitTest.h"
#include "../HW3/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Table_Tests)
	{
	public:
		
		TEST_METHOD(Resize)
		{
            Table t(2, 2);
            t[0][0] = 5.6;
            t[1][1] = 10.1;

            t.resize(3, 3);

			Assert::AreEqual(t[0][0], 5.5f);
			Assert::AreEqual(t[1][1], 10.1f);
			Assert::AreEqual(t[2][2],  0.0f);
		}

		TEST_METHOD(Operator_equal)
		{
			Table t1(2, 2);
			t1[0][0] = 1.0;

			Table t2(1, 1);
			t2 = t1;

			t1[0][0] = 99.0;

			Assert::AreEqual(t2[0][0], 1.0f);
		}

		TEST_METHOD(Out_of_Range)
		{
			Table t(2, 2);
			bool caughtException = false;

			try {
				t[0][5] = 10;
			}
			catch (const std::out_of_range&) {
				caughtException = true;
			}

			Assert::AreEqual(caughtException, true);
		}

		TEST_METHOD(Invalid_Argument)
		{
			Table t(2, 2);
			bool caughtException = false;

			try {
				t.resize(2, -3);
			}
			catch (const std::invalid_argument&) {
				caughtException = true;
			}

			Assert::AreEqual(caughtException, true);
		}

		TEST_METHOD(Search_Value)
		{
			Table t(2, 2);
			t[0][0] = 5.0;
			t[0][1] = 10.0;
			t[1][0] = 5.0;
			t[1][1] = 20.0;

			std::string result = t.search(5.0);

			std::string expected = "[0][0], [1][0]";

			Assert::AreEqual(expected, result);
		}
	};
}
