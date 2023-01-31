import math
import sys
sys.setrecursionlimit(10**8)

M = int(input())
N = int(input())

MAX = max(M + 1, N + 1)

isPrime = [True for _ in range(MAX)]

def prime():
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(math.sqrt(MAX)) + 1):
        if isPrime[i]:
            for j in range(i * 2, MAX, i):
                isPrime[j] = False

prime()

sum_res = 0
min_res = 987654321


for i in range(M, N + 1):
    if isPrime[i]:
        sum_res += i
        min_res = min(min_res, i)

if min_res == 987654321:
    print(-1)
else:
    print(sum_res)
    print(min_res)