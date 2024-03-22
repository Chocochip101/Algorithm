from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
tops = [0 for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    tops[b] += 1
    
answer = []
q = deque()
for i in range(1, N + 1):
    if tops[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    answer.append(now)
    
    for next in graph[now]:
        tops[next] -= 1
        if tops[next] == 0:
            q.append(next)
for i in answer:
    print(i, end=" ")