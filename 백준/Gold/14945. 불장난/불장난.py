import sys
sys.setrecursionlimit(10**8)
from collections import deque
input = sys.stdin.readline
MOD = 10007

N = int(input())
cache = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]

def solve(r, c):
    if r < 1 or c < 1 or c > r:
        return 0
    if r == 2 and c == 1:
        return 2
    if cache[r][c] != -1:
        return cache[r][c]
    cache[r][c] = (solve(r - 1, c) * 2 + solve(r - 1, c - 1) + solve(r - 1, c + 1) ) % MOD
    return cache[r][c] 

res = 0
for i in range(1, N):
    res += solve(N, i)
print(res % MOD)