def histogram(lens, char):
    blocks = []
    for len in lens:
        blocks.append(char*len)
    return " ".join(blocks)

print(histogram([6, 2, 15 , 3, 20 , 5], '=' ))
