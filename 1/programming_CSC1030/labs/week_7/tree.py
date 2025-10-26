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
        if not self.is_binary:
            return node.children
        children = []
        if node.left:
            children.append(node.left)
        if node.right:
            children.append(node.right)
        return children

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
        if self.root is None:
            return out
        stack = [self.root]
        while stack:
            cur = stack.pop()
            out.append(cur.val)
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
            if cur.children:
                stack += cur.children[::-1]
        return out

    # return array of values of all nodes in postorder
    def postorder(self):
        out = []
        seen = set()
        if self.root is None:
            return out
        stack = [self.root]
        while stack:
            cur = stack[-1]
            if self.is_leaf(cur) or cur in seen:
                out.append(cur.val)
                stack.pop()
                continue
            seen.add(cur)

            if cur.right:
                stack.append(cur.right)

            if cur.left:
                stack.append(cur.left)

            if cur.children:
                stack += cur.children[::-1]
        
        return out

    # return array of values of all nodes in inorder
    def inorder(self):
        out = []
        seen = set()
        if self.root is None:
            return out
        stack = [self.root]
        while stack:
            cur = stack[-1]
            if self.is_leaf(cur) or cur in seen:
                if self.is_binary:
                    out.append(cur.val)
                    stack.pop()
                    if len(stack) < 2:
                        continue

                    parent = stack.pop(-2)
                    out.append(parent.val)

                else:
                    if len(stack) >= 3:
                        parent = stack.pop(-3)
                        out.append(parent.val)

                    out.append(cur.val)
                    stack.pop()
                

            seen.add(cur)

            if cur.right:
                stack.append(cur.right)

            if cur.left:
                stack.append(cur.left)

            if cur.children:
                if not self.is_leaf(cur.children[0]):
                    stack += cur.children[::-1]
                    continue
                child_count = len(cur.children)
                i = 0
                while i < child_count//2:
                    c = cur.children[i]
                    out.append(c.val)
                    i += 1
                if i != 0:
                    out.append(cur.val)
                while i < child_count:
                    c = cur.children[i]
                    out.append(c.val)
                    i += 1
                if cur.val not in out:
                    out.append(cur.val)
                if stack:
                    stack.pop()
                
        
        return out

            

     
