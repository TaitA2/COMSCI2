"""------------------------------ Question 2------------------------------
Take the code below and implement the rotate_left() method. After running the program, the print out should look like this:

before rotation:

key: 10, value: 10_val, left: None, right: 20, parent: None

    key: 20, value: 20_val, left: None, right: 30, parent: 10

        key: 30, value: 30_val, left: None, right: None, parent: 20

after rotation:

key: 20, value: 20_val, left: 10, right: 30, parent: None

    key: 10, value: 10_val, left: None, right: None, parent: 20

    key: 30, value: 30_val, left: None, right: None, parent: 20

Code:"""

class TreeNode:

    def __init__(self, key, value, parent=None):

        self.key = key

        self.value = value

        self.left = None

        self.right = None

        self.parent = parent

    def __repr__(self):

        left_key = self.left.key if self.left else None

        right_key = self.right.key if self.right else None

        parent_key = self.parent.key if self.parent else None

        return f"key: {self.key}, value: {self.value}, left: {left_key}, right: {right_key}, parent: {parent_key}"

def rotate_left(node):

    # ************************ Implement Me *******************************
    # make right child of root the new root
    new_root = node.right
    new_root.parent = node.parent
    node.parent = new_root
    # if the new root has left child, move it to right child of old root
    node.right = new_root.left
    # make the current root the left child of the new root
    new_root.left = node


def print_tree(node, level=0):

    if not node:

        return

    indent = " " * (4 * level)

    print(f"{indent}{node}")

    if node.left:

        print_tree(node.left, level + 1)

    if node.right:

        print_tree(node.right, level + 1)

root = TreeNode(10, '10_val')

new_root = TreeNode(20, '20_val', root)

root.right = new_root

new_root.right = TreeNode(30, '30_val', new_root)

print("before rotation: ")

print_tree(root)

rotate_left(root)

print("\nafter rotation: ")

print_tree(new_root)

