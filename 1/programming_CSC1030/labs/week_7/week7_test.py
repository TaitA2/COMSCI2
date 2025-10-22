import unittest

# Q1 tests
from singly_linked_list import SinglyLinkedList

class TestSinglyLinkedList(unittest.TestCase):

    def setUp(self):
        self.a = SinglyLinkedList()
        self.b = SinglyLinkedList()

    def test_insert_start(self):
        self.a.insert_start(2)
        self.a.insert_start(1)
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)
        self.assertEqual(self.a.display(), "1 -> 2")

    def test_insert_end(self):
        self.a.insert_end(1)
        self.a.insert_end(2)
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)
        self.assertEqual(self.a.display(), "1 -> 2")

    def test_insert_sorted_into_empty(self):
        n = self.a.insert_sorted(5)
        self.assertEqual(self.a.head, n)
        self.assertEqual(self.a.tail, n)
        self.assertEqual(self.a.display(), "5")
        self.assertEqual(len(self.a), 1)
        n = self.a.insert_sorted(6)
        self.assertEqual(self.a.display(), "5 -> 6")

    def test_insert_sorted_maintains_order(self):
        for v in [10, 5, 20, 15, 8, 8]:
            self.a.insert_sorted(v)
        self.assertEqual(self.a.display(), "5 -> 8 -> 8 -> 10 -> 15 -> 20")
        self.assertEqual(self.a.head.val, 5)
        self.assertEqual(self.a.tail.val, 20)
        self.assertEqual(len(self.a), 6)

    def test_remove_start_empty(self):
        self.assertIsNone(self.a.remove_start())
        self.assertEqual(len(self.a), 0)

    def test_remove_start_single(self):
        self.a.insert_end(7)
        v = self.a.remove_start()
        self.assertEqual(v, 7)
        self.assertTrue(self.a.is_empty())
        self.assertIsNone(self.a.head)
        self.assertIsNone(self.a.tail)

    def test_remove_start_multiple(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        v = self.a.remove_start()
        self.assertEqual(v, 1)
        self.assertEqual(self.a.display(), "2 -> 3")
        self.assertEqual(self.a.head.val, 2)
        self.assertEqual(self.a.tail.val, 3)
        self.assertEqual(len(self.a), 2)

    def test_remove_end_empty(self):
        self.assertIsNone(self.a.remove_end())
        self.assertEqual(len(self.a), 0)

    def test_remove_end_single(self):
        self.a.insert_start(9)
        v = self.a.remove_end()
        self.assertEqual(v, 9)
        self.assertTrue(self.a.is_empty())
        self.assertIsNone(self.a.head)
        self.assertIsNone(self.a.tail)

    def test_remove_end_multiple(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        v = self.a.remove_end()
        self.assertEqual(v, 3)
        self.assertEqual(self.a.display(), "1 -> 2")
        self.assertEqual(self.a.head.val, 1)
        self.assertEqual(self.a.tail.val, 2)
        self.assertEqual(len(self.a), 2)

    def test_find_found(self):
        for v in [4, 5, 6]:
            self.a.insert_end(v)
        n = self.a.find(5)
        self.assertIsNotNone(n)
        self.assertEqual(n.val, 5)

    def test_find_not_found(self):
        for v in [1, 2, 3]:
            self.a.insert_end(v)
        self.assertIsNone(self.a.find(99))

    def test_is_empty(self):
        self.assertTrue(self.a.is_empty())
        self.a.insert_end(1)
        self.assertFalse(self.a.is_empty())
        self.a.remove_start()
        self.assertTrue(self.a.is_empty())

    def test_len(self):
        self.assertEqual(len(self.a), 0)
        for v in [1, 2, 3, 4]:
            self.a.insert_end(v)
        self.assertEqual(len(self.a), 4)
        self.a.remove_end()
        self.assertEqual(len(self.a), 3)

    def test_display(self):
        self.assertEqual(self.a.display(), "")
        for v in [1, 3, 2]:
            self.a.insert_end(v)
        self.assertEqual(self.a.display(), "1 -> 3 -> 2")


# Q2 tests
from tree import Tree

class TestTree(unittest.TestCase):
    def test_binary_tree_structure_and_leaf(self):
        t = Tree(is_binary=True)
        r = t.set_root(10)
        self.assertTrue(t.is_leaf(r))
        l = t.insert_left(r, 5)
        self.assertFalse(t.is_leaf(r))
        self.assertTrue(t.is_leaf(l))
        r2 = t.insert_right(r, 15)
        self.assertEqual([n.val for n in t.children(r)], [5, 15])
        self.assertEqual(t.size, 3)

    def test_binary_traversals(self):
        t = Tree(is_binary=True)
        r = t.set_root(10)
        a = t.insert_left(r, 5)
        b = t.insert_right(r, 15)
        t.insert_left(a, 2)
        t.insert_right(a, 7)
        t.insert_left(b, 12)
        t.insert_right(b, 20)
        self.assertEqual(t.preorder(), [10, 5, 2, 7, 15, 12, 20])
        self.assertEqual(t.inorder(), [2, 5, 7, 10, 12, 15, 20])
        self.assertEqual(t.postorder(), [2, 7, 5, 12, 20, 15, 10])

    def test_binary_enforcement(self):
        t = Tree(is_binary=True)
        r = t.set_root(1)
        with self.assertRaises(ValueError):
            t.add_child(r, 2)
        t.insert_left(r, 2)
        with self.assertRaises(ValueError):
            t.insert_left(r, 3)

    def test_general_tree_structure_and_leaf(self):
        t = Tree(is_binary=False)
        r = t.set_root("A")
        self.assertTrue(t.is_leaf(r))
        b = t.add_child(r, "B")
        c = t.add_child(r, "C")
        d = t.add_child(r, "D")
        self.assertFalse(t.is_leaf(r))
        self.assertTrue(t.is_leaf(b))
        self.assertEqual([n.val for n in t.children(r)], ["B", "C", "D"])
        self.assertEqual(t.size, 4)

    def test_general_traversals(self):
        t = Tree(is_binary=False)
        r = t.set_root("A")
        b = t.add_child(r, "B")
        c = t.add_child(r, "C")
        d = t.add_child(r, "D")
        t.add_child(b, "E")
        t.add_child(b, "F")
        t.add_child(d, "G")
        self.assertEqual(t.preorder(), ["A", "B", "E", "F", "C", "D", "G"])
        self.assertEqual(t.postorder(), ["E", "F", "B", "C", "G", "D", "A"])
        self.assertEqual(t.inorder(), ["E", "B", "F", "A", "C", "G", "D"])

    def test_general_enforcement(self):
        t = Tree(is_binary=False)
        r = t.set_root(1)
        with self.assertRaises(ValueError):
            t.insert_left(r, 2)
        with self.assertRaises(ValueError):
            t.insert_right(r, 3)

if __name__ == "__main__":
    unittest.main()
