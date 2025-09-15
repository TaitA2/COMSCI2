def filter_star(ratings, score):
    approved = dict()
    for k,v in ratings.items():
        if len(v) == score:
            approved[k] = v
    return approved if len(approved)>0 else "No results found!"




def histogram(lens, char):
    blocks = []
    for len in lens:
        blocks.append(char*len)
    return " ".join(blocks)



class Memories:
    def __init__(self, **kwargs):
        self.kwargs = kwargs
    def remember(self, key):
        val = self.kwargs.get(key)
        return val if val else False 
person1 = Memories(name='Tom', age=32, salary=50000)


def move_vow(s):
    vowels = ""
    consonants = ""
    for char in s:
        if char in "aeiouAEIOU":
            vowels += char
        else:
            consonants += char
    return vowels+consonants




def q1_sum(arrs):
    total = 0
    for arr in arrs:
        for i in arr:
            if i % 2 == 0:
                total += i
    return total

    


class Test:
    def __init__(self, subject_name, correct_answers, passing_mark):
        self.subject_name = subject_name
        self.correct_answers = correct_answers
        self.passing_mark = passing_mark

paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')       

class Student:
    def __init__(self, name):
        self.name = name

    def take_test(self, test, answers):
        q_val = 100 / len(answers)
        score = 0
        for i in range(len(answers)):
            if answers[i] == test.correct_answers[i]:
                score += q_val
        
        if score >= float(test.passing_mark[:-1]):
            return f"{self.name} passed the {test.subject_name} test with the score of {score:.1f}%!"
        return f"{self.name} failed the {test.subject_name} test!"

stu1 = Student('Tom')
stu2 = Student('John')
