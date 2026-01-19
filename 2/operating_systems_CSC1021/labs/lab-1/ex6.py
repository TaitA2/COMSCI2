from multiprocessing import *


def addTwoNumbers(a, b, q):
    q.put(a + b)


def addtwoPar():
    x = int(input("Enter first number: "))
    y = int(input("Enter second number: "))

    q = Queue()

    p1 = Process(target=addTwoNumbers, args=(x, y, q))
    p1.start()
    print(q.get())


addtwoPar()
