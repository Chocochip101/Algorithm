import sys
sys.setrecursionlimit(10**8)
from collections import deque
input = sys.stdin.readline
MAX = 200000

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(now):
    visited[now] = True
    for next in graph[now]:
        if not visited[next]:
            dfs(next)

res = 0         
for i in range(1, N + 1):
    if not visited[i]:
        res += 1
        dfs(i)
print(res)