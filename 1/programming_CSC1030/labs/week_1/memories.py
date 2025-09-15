class Memories:
    def __init__(self, **kwargs):
        self.kwargs = kwargs
    def remember(self, key):
        val = self.kwargs.get(key)
        return val if val else False 
person1 = Memories(name='Tom', age=32, salary=50000)
print(person1.remember('salary'))
print(person1.remember('email'))
