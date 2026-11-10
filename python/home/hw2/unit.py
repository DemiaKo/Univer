import unittest
import main

class TestMemoryAllocator(unittest.TestCase):
    def setUp(self):
        main.mem.clear()
        main.max_s = 100
        main.max_l = 20

    def test_malloc_invalid_size(self):
        self.assertEqual(main.malloc(0), -1)
        self.assertEqual(main.malloc(-5), -1)
        self.assertEqual(len(main.mem), 0)

    def test_malloc_empty_memory(self):
        res = main.malloc(20)
        self.assertEqual(res, 0)
        self.assertEqual(main.mem, [[0, 20]])

    def test_malloc_exceeds_max_s_empty(self):
        res = main.malloc(150)
        self.assertEqual(res, -1)
        self.assertEqual(len(main.mem), 0)

    def test_malloc_sequential(self):
        main.malloc(10)
        res = main.malloc(15)
        self.assertEqual(res, 10)
        self.assertEqual(main.mem, [[0, 10], [10, 15]])

    def test_free_existing_block(self):
        main.malloc(10)
        main.malloc(20)
        main.free(0)
        self.assertEqual(main.mem, [[10, 20]])

    def test_free_nonexistent_block(self):
        main.malloc(10)
        main.free(5)
        self.assertEqual(main.mem, [[0, 10]])

    def test_malloc_in_middle_space(self):
        main.malloc(10)
        main.malloc(20)
        main.malloc(10)
        
        main.free(10)
        
        res = main.malloc(15)
        self.assertEqual(res, 10)

        self.assertEqual(main.mem, [[0, 10], [10, 15], [30, 10]])

    def test_malloc_gap_too_small(self):
        main.malloc(10)
        main.malloc(10)
        main.malloc(10)
        
        main.free(10)
        
        res = main.malloc(15)
        self.assertEqual(res, 30)
        self.assertEqual(main.mem, [[0, 10], [20, 10], [30, 15]])

    def test_malloc_at_beginning(self):
        main.malloc(15)
        main.malloc(10)
        main.free(0)
        
        res = main.malloc(5)
        self.assertEqual(res, 0)
        self.assertEqual(main.mem, [[0, 5], [15, 10]])

if __name__ == '__main__':
    unittest.main()