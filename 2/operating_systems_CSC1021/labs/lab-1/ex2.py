from multiprocessing import *


def sayHi2(name):
    print("Hi", name, "from process", current_process().pid)


def manyGreetings():

    name = input("Enter your name: ")
    n = int(input("Enter number of processes: "))
    print("Hi from process", current_process().pid, "(main process)")

    for i in range(n):
        p = Process(target=sayHi2, args=(name,))

        p.start()


manyGreetings()
