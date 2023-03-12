import sys
import heapq
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
MAX = 2000010

N = int(input())
_li = []
for _ in range(N):
    X = int(input())
    if X == 0:
        if _li:
            print(heapq.heappop(_li))
        else:
            print(0)
    else:
        heapq.heappush(_li, X)