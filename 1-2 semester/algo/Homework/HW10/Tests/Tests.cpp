#include "pch.h"
#include "CppUnitTest.h"
#include "../HW10/AVLTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTreeTests
{
    TEST_CLASS(AVLTreeTests)
    {
    public:

        TEST_METHOD(TestRightRotation)
        {
            AVLTree tree;
            tree.insert(30);
            tree.insert(20);
            tree.insert(10);

            Assert::AreEqual(20, tree.getRootKey());
            Assert::AreEqual(2, tree.getRootHeight());
            Assert::IsTrue(tree.contains(10));
            Assert::IsTrue(tree.contains(30));
        }

        TEST_METHOD(TestLeftRotation)
        {
            AVLTree tree;
            tree.insert(10);
            tree.insert(20);
            tree.insert(30);

            Assert::AreEqual(20, tree.getRootKey());
            Assert::AreEqual(2, tree.getRootHeight());
        }

        TEST_METHOD(TestRightLeftRotation)
        {
            AVLTree tree;
            tree.insert(10);
            tree.insert(30);
            tree.insert(20);

            Assert::AreEqual(20, tree.getRootKey());
            Assert::AreEqual(2, tree.getRootHeight());
        }

        TEST_METHOD(TestRemoveOperations)
        {
            AVLTree tree;
            tree.insert(20);
            tree.insert(10);
            tree.insert(30);
            tree.insert(5);

            Assert::IsTrue(tree.contains(5));
            tree.remove(5);
            Assert::IsFalse(tree.contains(5));

            tree.remove(20);
            Assert::IsFalse(tree.contains(20));

            Assert::AreEqual(30, tree.getRootKey());
        }

        TEST_METHOD(TestExceptions)
        {
            AVLTree tree;
            tree.insert(50);

            auto funcInsert = [&] { tree.insert(50); };
            Assert::ExpectException<std::invalid_argument>(funcInsert);

            auto funcRemove = [&] { tree.remove(99); };
            Assert::ExpectException<std::invalid_argument>(funcRemove);
        }

        TEST_METHOD(TestDeepCopy)
        {
            AVLTree tree1;
            tree1.insert(100);
            tree1.insert(50);

            AVLTree tree2(tree1);

            tree1.insert(150);

            Assert::IsTrue(tree1.contains(150));
            Assert::IsFalse(tree2.contains(150));
        }
    };
}