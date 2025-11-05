"""------------------ Question 1 ------------------"""
class Position:

    def __init__(self, key, value, parent=None):
        self.key = key
        self.value = value
        self.parent = parent
        self.left = None
        self.right = None

    def __repr__(self):
        return f"({self.key}, {self.value})"

class BinarySearchTree:

    def __init__(self):
        self.root = None

    def upsert(self, key, val):

        if not self.root:
            self.root = Position(key, val)
            return self.root

        def _upsert(key, val, node, parent=None):

            if not node:
                return Position(key, val, parent)

            if key < node.key:
                node.left = _upsert(key, val, node.left, node)
            elif key > node.key:
                node.right = _upsert(key, val, node.right, node)
            else:
                node.value = val

            return node

        return _upsert(key, val, self.root)

    def find(self, key, node=None):

        if not node:
            node = self.root

        if key < node.key:
            return self.find(key, node.left)
        elif key > node.key:
            return self.find(key, node.right)
        else:
            return node

    def first(self, node=None):
        if not node:
            node = self.root
        if not node:
            return None

        while node.left:
            node = node.left
        return node


    def last(self, node=None):

        if not node:
            node = self.root

        if not node:
            return None


        while node.right:
            node = node.right
        return node

    def before(self, node):

        if not node:
            return None

        if node.left:
            return self.last(node.left)
        while node.parent and node.parent.right != node:
            node = node.parent
        return node.parent


    def print_tree(self):
        def display(node):
            """Return list of strings, width, height, and horizontal coordinate of root."""
            if node is None:
                return [], 0, 0, 0

            line = f"{node.key}({node.value})"
            width = len(line)

            left_lines, left_width, left_height, left_middle = display(node.left)
            right_lines, right_width, right_height, right_middle = display(node.right)

            first_line = second_line = ""
            if left_width > 0:
                first_line += " " * (left_middle + 1)
                first_line += "_" * (left_width - left_middle - 1)
                second_line += " " * left_middle + "/" + " " * (left_width - left_middle - 1)
            first_line += line
            second_line += " " * width
            if right_width > 0:
                first_line += "_" * right_middle + " " * (right_width - right_middle)
                second_line += " " * right_middle + "\\" + " " * (right_width - right_middle - 1)

            # Combine subtrees
            if left_height < right_height:
                left_lines += [" " * left_width] * (right_height - left_height)
            elif right_height < left_height:
                right_lines += [" " * right_width] * (left_height - right_height)

            zipped = zip(left_lines, right_lines)
            lines = [first_line, second_line] + [l + " " * width + r for l, r in zipped]
            return lines, left_width + width + right_width, max(left_height, right_height) + 2, left_width + width // 2

        lines, *_ = display(self.root)
        print("\n".join(lines))

    def after(self, node):
        if not node:
            return None

        if node.right:
            return self.first(node.right)

        def _after(node):

            if not node or not node.parent:
                return None

            if node.parent.left == node:
                return node.parent

            return _after(node.parent)

        return _after(node)

    def in_order_using_before(self):
        out = []
        cur = self.last()

        while cur and cur.key not in out:
            out = [cur.key]+out
            cur = self.before(cur)
        return out
    
    def in_order_using_after(self):
        out = []
        cur = self.first()

        while cur and cur.key not in out:
            out.append(cur.key)
            cur = self.after(cur)
        return out
                
    def delete(self, node):
        
        if self.root is node:
            if self.root.left and self.root.right:
                last = self.last(self.root.left) 
                last.right = self.root.right
                self.root.right.parent = last
                self.root = self.root.left
                self.root.parent = None
                return
                
            if self.root.left:
                self.root = self.root.left
                self.root.parent = None
                return
            elif self.root.right:
                self.root = self.root.right
                self.root.parent = None
                return
            else:
                self.root = None
                return

        cur = self.root
        while cur:
            if cur is node:
                if cur.left and cur.right:
                    cur.left.parent = cur.parent
                    last = self.last(cur.left)
                    cur.right.parent = last
                    last.right = cur.right
                    if cur == cur.parent.left:
                        cur.parent.left = cur.left
                        return
                    if cur == cur.parent.right:
                        cur.parent.right = cur.left
                        return
                if cur.left:
                    cur.parent.left = cur.left
                    cur.left.parent = cur.parent
                    return
                elif cur.right:
                    cur.parent.right = cur.right
                    cur.right.parent = cur.parent
                    return
                else:
                    if cur == cur.parent.left:
                        cur.parent.left = None
                        return
                    elif cur == cur.parent.right:
                        cur.parent.right = None
                        return
                return

            if node.key < cur.key:
                if cur.left:
                    cur = cur.left
                    continue
                else:
                    return
            elif node.key > cur.key:
                if cur.right:
                    cur = cur.right
                    continue
                else:
                    return
            else:
                return
