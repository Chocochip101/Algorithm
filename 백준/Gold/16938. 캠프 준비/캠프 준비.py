import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
from itertools import combinations

N, L, R, X = map(int, input().split())

A = list(map(int, input().split()))

res = 0
for i in range(2, N + 1):
    for problem_set in combinations(A, i):
        if L <= sum(problem_set) <= R and max(problem_set) - min(problem_set) >= X:
            res += 1
print(res)