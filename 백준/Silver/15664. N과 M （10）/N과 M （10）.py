from itertools import combinations

import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

N, M = map(int, input().split())

num = list(map(int, input().split()))
num.sort()

n_set = set()
for c in combinations(num, M):
    if c in n_set:
        continue
    for a in c:
        print(a, end=" ")
    print()
    n_set.add(c)
    