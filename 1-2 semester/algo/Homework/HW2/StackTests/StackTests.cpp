#include "pch.h"
#include "CppUnitTest.h"
#include "../HW2/Stack.h"
#include <stack>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
	TEST_CLASS(My_Stack)
	{
	public:
		
		TEST_METHOD(TestEmptyStack) {
			Stack<int> stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::AreEqual(0, stack.size());
		}

		TEST_METHOD(TestPushAndTop){
			Stack<int> stack;
			stack.push(42);

			Assert::IsFalse(stack.isEmpty());
			Assert::AreEqual(1, stack.size());
			Assert::AreEqual(42, stack.top());
		}

		TEST_METHOD(TestPop) {
			Stack<int> stack;
			stack.push(10);
			stack.push(20);

			stack.pop();

			Assert::AreEqual(1, stack.size());
			Assert::AreEqual(10, stack.top());
		}

		TEST_METHOD(TestDynamicResizing) {
			Stack<int> stack(2);

			stack.push(1);
			stack.push(2);
			stack.push(3);
			stack.push(4);

			Assert::AreEqual(4, stack.size());
			Assert::AreEqual(4, stack.top());

			stack.pop(); Assert::AreEqual(3, stack.top());
			stack.pop(); Assert::AreEqual(2, stack.top());
			stack.pop(); Assert::AreEqual(1, stack.top());
		}

		TEST_METHOD(TestSafeBehaviorOnEmpty){
			Stack<int> stack;

			stack.pop();
			Assert::IsTrue(stack.isEmpty());
			Assert::AreEqual(0, stack.size());

			Assert::AreEqual(0, stack.top());
		}
	};

	TEST_CLASS(STL_Stack)
	{
	public:

		TEST_METHOD(TestEmptyStack) {
			std::stack<int> stack;
			Assert::IsTrue(stack.empty());
			Assert::AreEqual(0, (int)stack.size());
		}

		TEST_METHOD(TestPushAndTop) {
			std::stack<int> stack;
			stack.push(42);

			Assert::IsFalse(stack.empty());
			Assert::AreEqual(1, (int)stack.size());
			Assert::AreEqual(42, stack.top());
		}

		TEST_METHOD(TestPop) {
			std::stack<int> stack;
			stack.push(10);
			stack.push(20);

			stack.pop();

			Assert::AreEqual(1, (int)stack.size());
			Assert::AreEqual(10, stack.top());
		}

		TEST_METHOD(TestDynamicResizing) {
			std::stack<int> stack;

			stack.push(1);
			stack.push(2);
			stack.push(3);
			stack.push(4);

			Assert::AreEqual(4, (int)stack.size());
			Assert::AreEqual(4, stack.top());

			stack.pop(); Assert::AreEqual(3, stack.top());
			stack.pop(); Assert::AreEqual(2, stack.top());
			stack.pop(); Assert::AreEqual(1, stack.top());
		}

		TEST_METHOD(TestSafeBehaviorOnEmpty) {
			std::stack<int> stack;

			stack.pop();
			Assert::IsTrue(stack.empty());
			Assert::AreEqual(0, (int)stack.size());

			Assert::AreEqual(0, stack.top());
		}
	};
}
