import math
import sys
from itertools import combinations

MAX = 10001
isPrime = [True for _ in range(MAX)]
isPrime[0] = isPrime[1] = False
for i in range(2, math.isqrt(MAX)):
    if isPrime[i]:
        for j in range(i*i, MAX, i):
            isPrime[j] = False

ans = set()
N, M = map(int, input().split())
H = list(map(int, input().split()))
for li in combinations(H, M):
    if isPrime[sum(li)]:
        ans.add(sum(li))

ans = sorted(ans)
if len(ans) == 0:
    print(-1)
else:
    for a in ans:
        print(a, end=' ')
