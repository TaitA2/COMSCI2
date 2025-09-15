def move_vow(s):
    vowels = ""
    consonants = ""
    for char in s:
        if char in "aeiouAEIOU":
            vowels += char
        else:
            consonants += char
    return vowels+consonants

print(move_vow('This is DCU!'))
