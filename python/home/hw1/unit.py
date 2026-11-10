import unittest
import main

class TestFibonacci(unittest.TestCase):
    def test_fib1_base_cases(self):
        self.assertEqual(main.fib1(0), 0)
        self.assertEqual(main.fib1(1), 1)

    def test_fib1_small_values(self):
        self.assertEqual(main.fib1(2), 1)
        self.assertEqual(main.fib1(5), 5)
        self.assertEqual(main.fib1(10), 55)

    def test_fib1_large_values(self):
        self.assertEqual(main.fib1(100), 354224848179261915075)

    def test_fib2_base_cases(self):
        self.assertEqual(main.fib2(0), 0)
        self.assertEqual(main.fib2(1), 1)

    def test_fib2_small_values(self):
        self.assertEqual(main.fib2(2), 1)
        self.assertEqual(main.fib2(5), 5)
        self.assertEqual(main.fib2(10), 55)

    def test_fib2_large_values(self):
        self.assertEqual(main.fib2(100), 354224848179261915075)

    def test_compare_fib1_and_fib2(self):
        for i in range(50):
            self.assertEqual(main.fib1(i), main.fib2(i))

unittest.main()