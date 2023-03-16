import sys
sys.setrecursionlimit(10**8)
from collections import deque
input = sys.stdin.readline
MAX = 200000

N, K = map(int, input().split())

dist = [-1 for _ in range(MAX)]
def bfs(src):
    q = deque()
    q.append(src)
    dist[src] = 0
    while q:
        now = q.popleft()
        if now == K:
            return
        
        if now - 1 >= 0 and dist[now - 1] == -1:
            dist[now - 1] = dist[now] + 1
            q.append(now - 1)
        if now + 1 < MAX and dist[now + 1] == -1:
            dist[now + 1] = dist[now] + 1
            q.append(now + 1)
        if now * 2 < MAX and dist[now * 2] == -1:
            dist[now * 2] = dist[now] + 1
            q.append(now * 2)
bfs(N)
print(dist[K])