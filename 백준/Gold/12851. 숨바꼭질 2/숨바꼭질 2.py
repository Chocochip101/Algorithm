from collections import deque
N, K = map(int, input().split())
MAX = 100_100
q = deque()
q.append([N, 0])

visited = [False for _ in range(MAX)]
minDist = -1
ans = 0
while q:
    now, dist = q.popleft()
    visited[now] = True
    
    if minDist == dist and now == K:
        ans += 1
        
    if minDist == -1 and now == K:
        minDist = dist
        ans += 1
        
    if now - 1 >= 0  and not visited[now - 1]:
        q.append([now - 1, dist + 1])
    if now + 1 < MAX  and not visited[now + 1]:
        q.append([now + 1, dist + 1])
    if now * 2 < MAX  and not visited[now * 2]:
        q.append([now * 2, dist + 1])

print(minDist)
print(ans)
