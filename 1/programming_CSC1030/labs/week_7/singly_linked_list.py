# Node class
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

# Singly Linked List class
class SinglyLinkedList:

    # initialiser method
    def __init__(self):
        self.head = None
        self.tail = None

    # insert val at start of linked list
    def insert_start(self, val):
        node = Node(val)
        node.next = self.head
        self.head = node
        if not self.tail:
            self.tail = node

    # insert val at end of linked list
    def insert_end(self, val):
        node = Node(val)
        if self.tail:
            self.tail.next = node
        self.tail = node
        if not self.head:
            self.head = node

    # insert val at appropriate spot in sorted list
    def insert_sorted(self, val):
        node = Node(val)
        # base case for empty linked list
        if self.head == None and self.tail == None:
            self.head = node
            self.tail = node
            return node

        cur = self.head
        while cur.next != None and cur.next.next != None:
            if cur.val <= val and cur.next.val >= val:
                node.next = cur.next
                cur.next = node
                return node
            cur = cur.next
        if not cur.next:
            self.tail.next = node
            self.tail = node
            return node
            

    # remove the node at the start 
    def remove_start(self):
        if self.head == None:
            return
        v = self.head.val
        self.head = self.head.next
        if not self.head:
            self.tail = None
        return v

    # remove the node at the end
    def remove_end(self):
        if self.head == None:
            return
        if self.head.next == None:
            v = self.head.val
            self.head = self.tail = None 
            return v
        if len(self) == 2:
            self.head.next = None
            self.tail = self.head
            return self.head.val
        cur = self.head
        oldtail = self.tail
        while cur != None and cur.next != None and cur.next.next != None:
            cur = cur.next
        cur.next = None
        self.tail = cur
        return oldtail.val

    # return the node with the given value
    def find(self, val):
        if self.head == None:
            return 
        cur = self.head
        while cur != None and cur.val != val:
            cur = cur.next
        if cur:
            return cur

    # check if head node is None
    def is_empty(self):
        return self.head is None and self.tail is None

    # return the length of the linked list
    def __len__(self):
        length = 0
        cur = self.head
        while cur != None:
            length += 1
            cur = cur.next
        return length

    # return a string representation of the linked list in format: Node1.val -> Node2.val -> etc.
    def display(self):
        vals = []
        if self.head == None:
            return ""
        cur = self.head
        while cur != None:
            vals.append(str(cur.val))
            cur = cur.next
        return " -> ".join(vals)

ll = SinglyLinkedList()
ll.insert_start(1)
ll.insert_start(2)
print(ll.tail.val)
