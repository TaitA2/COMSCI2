from multiprocessing import *


def sayHi():
    print("Hi from process", current_process().pid)


def procEx():
    print("Hi from process", current_process().pid, "(parent process)")

    p1 = Process(target=sayHi, args=())
    p2 = Process(target=sayHi, args=())
    p3 = Process(target=sayHi, args=())

    p1.start()
    p2.start()
    p3.start()


procEx()
