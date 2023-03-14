import sys
sys.setrecursionlimit(10**8)
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
M = int(input())
recommends = list(map(int, input().split()))

di = defaultdict(int)

for i in range(M):
    if len(di) < N:
        di[recommends[i]] += 1
    elif len(di) == N:
        if recommends[i] in di.keys():
            di[recommends[i]] += 1
        else:
            min_key = min(di, key=di.get)
            di.pop(min_key)
            di[recommends[i]] += 1
for i in sorted(di):
    print(i, end=" ")
        