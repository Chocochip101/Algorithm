import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
visited = [False for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    if u > v:
        graph[v - 1].append(u - 1)
    else:
        graph[u - 1].append(v - 1)


def solve(now, cnt):
    if now == N:
        return cnt
    if visited[now]:
        return solve(now + 1, cnt)
    
    res = 0
    
    for next in graph[now]:
        if not visited[next]:
            visited[next] = True
            res = max(res, solve(now + 1, cnt + 1))
            visited[next] = False
            
    return max(res, solve(now + 1, cnt))

res = solve(0, 0)
res *= 2

if N > res:
    print(res + 1)
else:
    print(res)