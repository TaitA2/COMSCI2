# Q1
class Queue:
    def __init__(self):
        self.queue = list()

    def enqueue(self, val):
        self.queue.append(val)

        
    def dequeue(self):
        return self.queue.pop(0)

    def first(self):
        return self.queue[0]

    def size(self):
        return len(self.queue)

    def is_empty(self):
        return self.size() == 0

    def __str__(self):
        return "Front -> " + " | ".join(str(i) for i in self.queue) + " <- Back"

    def reverse(self):
        if self.is_empty():
            return
        front = self.dequeue()
        self.reverse()
        self.enqueue(front)

    def find_minimum(self):
        if self.is_empty():
            return None
        if self.size() == 1:
            return self.first()

        x = self.dequeue()

        m = self.find_minimum()

        if x < m:
            return x

        return m

q = Queue()
for i in range(10):
    q.enqueue(i)
print("Queue: ", q)
q.reverse()
print("Reversed Queue: ", q)

print("Minimum: ", q.find_minimum())

# Q2
def get_binary(n):
    q = Queue()
    q.enqueue("1")
    binary = list()

    for _ in range(n):
        cur = q.dequeue()
        binary.append(cur)
        q.enqueue(cur + "0")
        q.enqueue(cur + "1")
    return binary
n = 16
binary = get_binary(n)
print(" ".join(binary))

# Q3
class Stack:
    def __init__(self):
        self.stack = list()

    def is_empty(self):
        return len(self.stack) == 0

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        return self.stack.pop()

    def top(self):
        return self.stack[-1]
    def size(self):
        return len(self.stack)
    
stack = Stack()
result = list()
for char in "EAS*Y*QUE***ST***IO*N***":
    if char == "*":
        result.append(stack.pop())
    else:
        stack.push(char)
print(result)

# Q4
q = Queue()
result = list()
for char in "EAS*Y*QUE***ST***IO*N***":
    if char == "*":
        result.append(q.dequeue())
    else:
        q.enqueue(char)
print(result)

# Q5
s = "print me in reverse!!"
print(s)
stack = Stack()
for char in s:
    stack.push(char)
result = ""
while not stack.is_empty():
    result += stack.pop()
print(result)

# Q6
def postfix(s):
    operators = "^*+-/()"
    stack = Stack()
    for char in s:
        if char not in operators:
            stack.push(int(char))
        else:
            b = stack.pop()
            a = stack.pop()
            op_dict = {"+": a + b, "-": a - b, "*": a * b, "/": a / b, "^": a ** b}
            stack.push(op_dict[char])

    return stack.pop()
    
print("Postfix: ", postfix("1432^*+147--+"))

# Q7

class Double_Queue(Queue):
    def pop(self):
        return self.queue.pop()
    def add_first(self, val):
        self.queue.insert(0, val)
    

def palindrom(s):
    dq = Double_Queue()
    for char in s:
        dq.enqueue(char)
    while dq.size() >= 2:
        f = dq.dequeue().lower()
        l = dq.pop().lower()
        if f != l:
            return False
    return True
s = "Navan"
print(s, " is palindrom: ", palindrom(s))
s = "Bob"
print(s, " is palindrom: ", palindrom(s))
s = "Not"
print(s, " is palindrom: ", palindrom(s))

