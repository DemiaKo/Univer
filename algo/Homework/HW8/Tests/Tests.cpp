#include "pch.h"
#include "CppUnitTest.h"
#include "../HW8/Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomSetTests
{
    TEST_CLASS(CustomSetTests)
    {
    public:
        TEST_METHOD(Test1_InsertionAndSize)
        {
            CustomSet<int> s;
            Assert::AreEqual(static_cast<size_t>(0), s.size());

            Assert::IsTrue(s.insert(10));
            Assert::IsTrue(s.insert(20));
            Assert::AreEqual(static_cast<size_t>(2), s.size());

            Assert::IsFalse(s.insert(10));
            Assert::AreEqual(static_cast<size_t>(2), s.size());
        }

        TEST_METHOD(Test2_ContainsElement)
        {
            CustomSet<int> s;
            s.insert(5);
            s.insert(15);

            Assert::IsTrue(s.contains(5));
            Assert::IsTrue(s.contains(15));
            Assert::IsFalse(s.contains(99));
        }

        TEST_METHOD(Test3_EraseAndExceptions)
        {
            CustomSet<int> s;
            s.insert(100);
            s.insert(200);

            Assert::IsTrue(s.contains(100));
            s.erase(100);
            Assert::IsFalse(s.contains(100));
            Assert::AreEqual(static_cast<size_t>(1), s.size());

            auto tryEraseMissing = [&] { s.erase(999); };
            Assert::ExpectException<std::invalid_argument>(tryEraseMissing);
        }

        TEST_METHOD(Test4_UnionOperation)
        {
            CustomSet<int> s1;
            s1.insert(1);
            s1.insert(2);

            CustomSet<int> s2;
            s2.insert(2);
            s2.insert(3);

            CustomSet<int> result = s1.unionWith(s2);

            Assert::AreEqual(static_cast<size_t>(3), result.size());
            Assert::IsTrue(result.contains(1));
            Assert::IsTrue(result.contains(2));
            Assert::IsTrue(result.contains(3));
        }

        TEST_METHOD(Test5_IntersectionOperation)
        {
            CustomSet<int> s1;
            s1.insert(1);
            s1.insert(2);
            s1.insert(3);

            CustomSet<int> s2;
            s2.insert(2);
            s2.insert(3);
            s2.insert(4);

            CustomSet<int> result = s1.intersectWith(s2);

            Assert::AreEqual(static_cast<size_t>(2), result.size());
            Assert::IsTrue(result.contains(2));
            Assert::IsTrue(result.contains(3));
            Assert::IsFalse(result.contains(1));
            Assert::IsFalse(result.contains(4));
        }

        TEST_METHOD(Test6_DifferenceOperation)
        {
            CustomSet<int> s1;
            s1.insert(1);
            s1.insert(2);
            s1.insert(3);

            CustomSet<int> s2;
            s2.insert(3);
            s2.insert(4);

            CustomSet<int> result = s1.differenceWith(s2);

            Assert::AreEqual(static_cast<size_t>(2), result.size());
            Assert::IsTrue(result.contains(1));
            Assert::IsTrue(result.contains(2));
            Assert::IsFalse(result.contains(3));
        }
    };
}