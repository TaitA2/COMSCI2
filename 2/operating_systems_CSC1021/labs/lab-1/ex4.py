from multiprocessing import *


def sayHi4(lock, name, hole):
    lock.acquire()

    print("Hiddy-ho!  I'm worker", name, "and today I have to dig hole", hole)

    lock.release()


def assignDiggers():
    lock1 = Lock()

    for i in range(10):
        Process(target=sayHi4, args=(lock1, chr(ord("A") + i), i)).start()


assignDiggers()
