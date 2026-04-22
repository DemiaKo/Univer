#include "pch.h"
#include "CppUnitTest.h"
#include "../HW7/Classes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueUnitTests
{
    TEST_CLASS(QueueUnitTests)
    {
    public:

        TEST_METHOD(TestPushAndPop_FIFO)
        {
            Queue<int> q(5);
            q.push(10);
            q.push(20);

            Assert::AreEqual(10, q.pop());
            Assert::AreEqual(20, q.pop());
            Assert::IsTrue(q.empty());
        }

        TEST_METHOD(TestResizeOnOverflow)
        {
            Queue<int> q(2);
            q.push(1);
            q.push(2);
            q.push(3);

            Assert::AreEqual(1, q.pop());
            Assert::AreEqual(2, q.pop());
            Assert::AreEqual(3, q.pop());
        }

        TEST_METHOD(TestPopExceptionWhenEmpty)
        {
            Queue<int> q(2);

            auto func = [&] { q.pop(); };

            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(TestConstructorExceptionInvalidCapacity)
        {
            auto func = [&] { Queue<int> q(-5); };

            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestFrontMethod)
        {
            Queue<int> q(5);
            q.push(42);
            q.push(99);

            Assert::AreEqual(42, q.front());
            Assert::AreEqual(42, q.pop());
            Assert::AreEqual(99, q.front());
        }

        TEST_METHOD(TestDeepCopyConstructor)
        {
            Queue<int> original(3);
            original.push(1);
            original.push(2);

            Queue<int> copy(original);

            original.pop();
            original.push(3);

            Assert::AreEqual(1, copy.pop());
            Assert::AreEqual(2, copy.pop());
            Assert::IsTrue(copy.empty());
        }
    };

    TEST_CLASS(PriorityQueueUnitTests)
    {
    public:

        TEST_METHOD(TestPushAndPop_PriorityOrder)
        {
            PriorityQueue<std::string> pq(5);

            pq.push("Студент (Низький)", 1);
            pq.push("Швидка допомога (Високий)", 10);
            pq.push("Доставка (Середній)", 5);

            Assert::AreEqual(std::string("Швидка допомога (Високий)"), pq.pop());
            Assert::AreEqual(std::string("Доставка (Середній)"), pq.pop());
            Assert::AreEqual(std::string("Студент (Низький)"), pq.pop());

            Assert::IsTrue(pq.empty());
        }

        TEST_METHOD(TestTopMethod)
        {
            PriorityQueue<int> pq(5);
            pq.push(100, 2);
            pq.push(200, 5);

            Assert::AreEqual(200, pq.top());
            Assert::AreEqual(2, pq.size());

            pq.pop();
            Assert::AreEqual(100, pq.top());
        }

        TEST_METHOD(TestResizeOnOverflow)
        {
            PriorityQueue<int> pq(2);

            pq.push(10, 1);
            pq.push(20, 2);
            pq.push(30, 3);

            Assert::AreEqual(3, pq.size());
            Assert::AreEqual(30, pq.pop());
            Assert::AreEqual(20, pq.pop());
            Assert::AreEqual(10, pq.pop());
        }

        TEST_METHOD(TestExceptionsOnEmptyQueue)
        {
            PriorityQueue<int> pq(5);

            auto funcPop = [&] { pq.pop(); };
            Assert::ExpectException<std::out_of_range>(funcPop);

            auto funcTop = [&] { pq.top(); };
            Assert::ExpectException<std::out_of_range>(funcTop);
        }

        TEST_METHOD(TestConstructorExceptionInvalidCapacity)
        {
            auto funcZero = [&] { PriorityQueue<int> pq(0); };
            Assert::ExpectException<std::invalid_argument>(funcZero);

            auto funcNegative = [&] { PriorityQueue<int> pq(-5); };
            Assert::ExpectException<std::invalid_argument>(funcNegative);
        }
    };
}