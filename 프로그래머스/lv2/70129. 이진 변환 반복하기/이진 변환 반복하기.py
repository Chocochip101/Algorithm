def transform(n):
    res = ''
    while n > 0:
        if n % 2 == 0:
            res = '0' + res
        else:
            res = '1' + res
        n //= 2
    return res

def count_zero(s):
    zeros = 0
    for i in range(len(s)):
        if s[i] == '0':
            zeros += 1
    return zeros
            
def solution(s):
    cnt = 0
    zeros = 0
    while len(s) > 1:
        zeros += count_zero(s)
        s = transform(len(s) - count_zero(s))
        cnt += 1
    return [cnt, zeros]