def sum(n):

    if n == 0:
        return n

    return n + sum(n-1)

print(sum(3))
print(sum(6))

########################################

def rev(n, r=0):

    if n == 0:
        return r

    last = n % 10
    pre = n // 10
    r = r * 10 + last

    return rev(pre, r)

print(rev(123))

#############################

def rev(str):

    if not str:
        return ''

    return str[len(str)-1] + rev(str[:-1])

print(rev("hello"))

#######################################

def mul(x, y):

    if y == 0:
        return 0

    if x < 0 and y < 0:
        return mul(-x, -y)
    elif y < 0:
        return -mul(x, -y)

    return x + mul(x, y-1)

print(mul(10, 2))
print(mul(-51, -4))
print(mul(51, -4))
print(mul(-51, 4))


#######################

def is_h(x, n=0):

    if n * (n+1) < x:
        return is_h(x, n+1)
    else:
        return n * (n+1) == x

print(is_h(6))
print(is_h(110))
print(is_h(111))

####################################

def length_of_str(str):

    if not str:
        return 0

    return 1 + length_of_str(str[:-1])

print(length_of_str("Tom"))
print(length_of_str("Tommy"))


