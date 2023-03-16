import sys
sys.setrecursionlimit(10**8)
from itertools import combinations
input = sys.stdin.readline


N, M = map(int, input().split())
trees = list(map(int, input().split()))
def solve(n):
    res = 0
    for i in range(N):
        if trees[i] > n:
            res += (trees[i] - n)
    return res
        
l = 0
h = max(trees)

ans = -1
while l <= h:
    mid = (l + h) // 2
    res = solve(mid)
    
    if res < M:
        h = mid - 1
    else:
        ans = max(ans, mid)
        l = mid + 1
print(ans)
