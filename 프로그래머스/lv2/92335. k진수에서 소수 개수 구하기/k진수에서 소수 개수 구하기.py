import math

def isPrime(a):
    if(a<2):
        return False
    for i in range(2, int(math.sqrt(a)) + 1):
        if(a%i==0):
            return False
    return True

def solution(n, k):
    _n = 0
    cnt = 1
    while n > 0:
        _n += (n % k) * cnt
        n //= k
        cnt *= 10
    _n = str(_n)
    pri_cand = _n.split('0')
    answer = 0
    for cand in pri_cand:
        if cand != "" and isPrime(int(cand)):
            answer += 1
    return answer

print(solution(0, 10))