# munchhausen problem in py


def is_munch(n):
    orig = n
    v = 0

    while n:
        i = n % 10
        v += i**i
        n //= 10

    return v == orig


for i in range(1, 10**7):
    if is_munch(i):
        print(i)
