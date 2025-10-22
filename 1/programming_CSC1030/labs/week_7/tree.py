# Tree Node class
class TreeNode:
    # initialise node
    def __init__(self, val):
        self.val = val
        self.parent = None
        self.children = []
        self.left = None
        self.right = None

# Tree class
class Tree:
    # initialise tree
    def __init__(self, is_binary=True):
        self.is_binary = is_binary
        self.root = None
        self.size = 0

    # set the root node to a new node with the given val
    def set_root(self, val):
        self.root = TreeNode(val)
        if self.size == 0:
            self.size = 1 
        return self.root

    # return boolean node has no children
    def is_leaf(self, node):
        return len(node.children) == 0 and not node.left and not node.right

    # return array of nodes children of node provided
    def children(self, node):
        return node.children

    # add a new node with given val as a child of parent node provided
    def add_child(self, parent, val):
        if self.is_binary:
            raise ValueError("use insert_left/insert_right for binary trees")
        child = TreeNode(val)
        parent.children.append(child)
        self.size += 1
        return child

    # set new node with given val as left child of parent node provided
    def insert_left(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.left is not None:
            raise ValueError("left already set")

        node = TreeNode(val)
        parent.left = node
        self.size += 1
        return node

    # set new node with given val as right child of parent node provided
    def insert_right(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.right is not None:
            raise ValueError("right already set")
        node = TreeNode(val)
        parent.right = node
        self.size += 1
        return node

    # return array of values of all nodes in preorder
    def preorder(self):
        out = []
        pass

    # return array of values of all nodes in postorder
    def postorder(self):
        out = []
        pass

    # return array of values of all nodes in inorder
    def inorder(self):
        out = []
        pass

     
