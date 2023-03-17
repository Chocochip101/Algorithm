import sys
sys.setrecursionlimit(10**8)
from collections import deque
input = sys.stdin.readline
MAX = 200000

N, M = map(int, input().split())
indegree = [0 for _ in range(N + 1)]
graph = [[] for _ in range(N + 1)]
res = [1 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

q = deque()
for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    for next in graph[now]:
        res[next] = res[now] + 1
        indegree[next] -= 1
        if indegree[next] == 0:
            q.append(next)
    
for i in range(1, N + 1):
    print(res[i], end= ' ')