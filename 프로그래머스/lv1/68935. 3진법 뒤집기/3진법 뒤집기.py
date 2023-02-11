def toTen(s):
    res = 0
    for i in range(len(s) - 1, -1, -1):
        res += (3 ** i) * int(s[i])
    return res

def toThree(n):
    res = ''
    while n > 0:
        if n % 3 == 0:
            res = '0' + res
        elif n % 3 == 1:
            res = '1' + res
        else:
            res = '2' + res
        n //= 3
    return res

def solution(n):
    return toTen(toThree(n))