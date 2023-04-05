import sys
from itertools import combinations

N, M = map(int, input().split())
board = []
chick_points = []
house_points = []
for i in range(N):
    _li = list(map(int, input().split()))
    for j in range(N):
        if _li[j] == 2:
            chick_points.append((i, j))
        elif _li[j] == 1:
            house_points.append((i, j))

def dist(a, b, c, d):
    return abs(a - c) + abs(b - d)

ans = float('inf')
for chick in combinations(chick_points, M):
    total = 0
    for hx, hy in house_points:
        temp = float('inf')
        for cx, cy in chick:
            temp = min(temp, dist(hx, hy, cx, cy))
        total += temp
    ans = min(ans, total)
print(ans)