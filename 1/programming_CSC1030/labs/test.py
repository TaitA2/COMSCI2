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
print(stu1.take_test(paper2, ['1C', '2C', '3D', '4A']))
stu2 = Student('John')
print(stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B']) )
