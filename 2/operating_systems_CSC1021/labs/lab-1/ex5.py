from multiprocessing import *
import time


def greet(q):
    for _ in range(5):
        print("(child process) Waiting for name...")
        name = q.get()
        print("(child process) Well, hi", name)


def sendName():
    q = Queue()

    p1 = Process(target=greet, args=(q,))
    p1.start()

    for i in range(5):
        time.sleep(1)  # wait for 5 seconds
        print("(parent process) Ok, I'll send the name")
        q.put("Jimmy" + str(i))


sendName()
