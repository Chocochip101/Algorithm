import imp
import sys
import math
from itertools import permutations
MAX = 1000001
isPrime = [True] * MAX

def makePrime():
    isPrime[0] = False
    isPrime[1] = False
    isPrime[2] = True
    for i in range(int(math.sqrt(MAX)) + 1):
        if isPrime[i]:
            for j in range(i*i, MAX, i):
                isPrime[j] = False

def dd(num, k):
    if num < k: return num
    while 1:
        if(num % k != 0): return num
        num //= k
    return num
        
def cond1(n):
    for i in range(2, n // 2 + 1):
        if i != n - i and isPrime[i] and isPrime[n - i]:
            return True
    return False


def cond2(n, k):
    n = dd(n, k)
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and isPrime[i] and isPrime[n // i]:
            return True
    return False

makePrime()
K, M = map(int, input().split())
ans = 0
for num in permutations(['0', '1', '2', '3', '4', '5', '6', '7','8', '9'], K):
    if(num[0] == '0'): continue
    num = int(''.join(num))
    if(cond1(num)):
        if(cond2(num, M)):
            ans += 1
            
print(ans)