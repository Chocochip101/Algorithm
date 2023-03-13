from collections import defaultdict
import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]


for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
ans = 0
def dfs(now):
    global ans
    visited[now] = True
    for next in graph[now]:
        if not visited[next]:
            ans += 1
            dfs(next)

dfs(1)
print(ans)