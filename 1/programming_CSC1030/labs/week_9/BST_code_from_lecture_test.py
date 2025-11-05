import unittest

from BST_code_from_lecture import BinarySearchTree

class TestTree(unittest.TestCase):

    def test_upsert(self):
        bst = BinarySearchTree()
        bst.upsert(50, "50_val")
        self.assertEqual(bst.root.value, "50_val")
        bst.upsert(60, "60_val")
        self.assertEqual(bst.root.right.value, "60_val")
        bst.upsert(55, "55_val")
        self.assertEqual(bst.root.right.left.value, "55_val")

    def test_first(self):
        bst = BinarySearchTree()
        bst.upsert(50, "50_val")
        bst.upsert(20, "20_val")
        bst.upsert(10, "10_val")
        bst.upsert(30, "35_val")
        bst.upsert(60, "65_val")

        first = bst.first()
        self.assertEqual(10, first.key)

    def test_last(self):
        bst = BinarySearchTree()
        bst.upsert(50, "50_val")
        bst.upsert(20, "20_val")
        bst.upsert(10, "10_val")
        bst.upsert(30, "30_val")
        bst.upsert(60, "60_val")

        last = bst.last()
        self.assertEqual(60, last.key)

    def test_before(self):
        bst = BinarySearchTree()
        bst.upsert(50, "50_val")
        bst.upsert(20, "20_val")
        bst.upsert(10, "10_val")
        bst.upsert(30, "30_val")
        bst.upsert(60, "60_val")

        last = bst.last()
        self.assertEqual(60, last.key)

    def test_before_no_left(self):
        bst = BinarySearchTree()
        bst.upsert(50, "50_val")
        bst.upsert(20, "20_val")
        bst.upsert(10, "10_val")
        bst.upsert(30, "30_val")
        bst.upsert(60, "60_val")

        node = bst.find(60)

        before = bst.before(node)
        self.assertEqual(50, before.key)

