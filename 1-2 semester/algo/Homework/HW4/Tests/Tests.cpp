#include "pch.h"
#include "CppUnitTest.h"
#include "../HW4/Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(HashTableTests)
	{
	public:
		
        TEST_METHOD(TestBasicInsertAndGet)
        {
            Table t;
            t.insert("Apple", 10);
            t.insert("Banana", 20);

            Assert::AreEqual(10, t.get("Apple"));
            Assert::AreEqual(20, t.get("Banana"));
        }

        TEST_METHOD(TestUpdateExistingKey)
        {
            Table t;
            t.insert("Orange", 5);

            t.insert("Orange", 15);
            Assert::AreEqual(15, t.get("Orange"));

            t["Orange"] = 30;
            Assert::AreEqual(30, t.get("Orange"));
        }

        TEST_METHOD(TestCollisionHandling)
        {
            Table t(5);

            t.insert("AB", 100);
            t.insert("BA", 200);

            Assert::AreEqual(100, t.get("AB"));
            Assert::AreEqual(200, t.get("BA"));
        }

        TEST_METHOD(TestExceptionOnMissingKey)
        {
            Table t;
            t.insert("Apple", 10);

            auto funcGet = [&] { t.get("Mango"); };
            Assert::ExpectException<std::out_of_range>(funcGet);

            auto funcRemove = [&] { t.remove("Kiwi"); };
            Assert::ExpectException<std::out_of_range>(funcRemove);
        }

        TEST_METHOD(TestResizeTrigger)
        {
            Table t(5);

            t.insert("A", 1);
            t.insert("B", 2);
            t.insert("C", 3);

            t.insert("D", 4);
            t.insert("E", 5);
            t.insert("F", 6);

            Assert::AreEqual(1, t.get("A"));
            Assert::AreEqual(3, t.get("C"));
            Assert::AreEqual(6, t.get("F"));
        }

        TEST_METHOD(TestAssignmentOperatorDeepCopy)
        {
            Table t1;
            t1.insert("Apple", 10);
            t1.insert("Banana", 20);

            Table t2;
            t2.insert("Orange", 99);

            t2 = t1;

            Assert::AreEqual(10, t2.get("Apple"));
            Assert::AreEqual(20, t2.get("Banana"));

            auto funcGetOld = [&] { t2.get("Orange"); };
            Assert::ExpectException<std::out_of_range>(funcGetOld);
            t2["Apple"] = 500;
            t2.insert("Mango", 30);

            Assert::AreEqual(500, t2.get("Apple"));
            Assert::AreEqual(10, t1.get("Apple"));

            auto funcGetMangoFromT1 = [&] { t1.get("Mango"); };
            Assert::ExpectException<std::out_of_range>(funcGetMangoFromT1);

            t1 = t1;
            Assert::AreEqual(10, t1.get("Apple"));
        }
	};
}
