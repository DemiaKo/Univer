#include "pch.h"
#include "CppUnitTest.h"
#include <algorithm>
#include "../HW1/Algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTests {

	TEST_CLASS(MergeSortTests) {
	public:
		TEST_METHOD(NormalArrayTest) {
			int arr[] = { 12, 11, 13, 5, 6, 7 };
			int n = sizeof(arr) / sizeof(arr[0]);

			mergeSort(arr, 0, n - 1);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(AlreadySortedTest) {
			int arr[] = { 1, 2, 3, 4, 5 };
			int n = sizeof(arr) / sizeof(arr[0]);

			mergeSort(arr, 0, n - 1);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(ReverseSortedTest) {
			int arr[] = { 10, 9, 8, 7, 6 };
			int n = sizeof(arr) / sizeof(arr[0]);

			mergeSort(arr, 0, n - 1);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(DuplicatesTest) {
			int arr[] = { 5, 2, 5, 2, 5, 5 };
			int n = sizeof(arr) / sizeof(arr[0]);

			mergeSort(arr, 0, n - 1);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}
	};

	TEST_CLASS(StrandSortTests) {
	public:
		TEST_METHOD(NormalArrayTest) {
			int arr[] = { 12, 11, 13, 5, 6, 7 };
			int n = sizeof(arr) / sizeof(arr[0]);

			strandSort(arr, n);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(AlreadySortedTest) {
			int arr[] = { 1, 2, 3, 4, 5 };
			int n = sizeof(arr) / sizeof(arr[0]);

			strandSort(arr, n);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(ReverseSortedTest) {
			int arr[] = { 10, 9, 8, 7, 6 };
			int n = sizeof(arr) / sizeof(arr[0]);

			strandSort(arr, n);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}

		TEST_METHOD(DuplicatesTest) {
			int arr[] = { 5, 2, 5, 2, 5, 5 };
			int n = sizeof(arr) / sizeof(arr[0]);

			strandSort(arr, n);
			Assert::IsTrue(std::is_sorted(arr, arr + n));
		}
	};
}
