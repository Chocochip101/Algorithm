import sys
import heapq
input = sys.stdin.readline

N = int(input())
M = int(input())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])

distance = [float('inf') for _ in range(N + 1)]
trace = [i for i in range(N + 1)]

def dijkstra(src):
    distance[src] = 0
    q = []
    heapq.heappush(q, [0, src])
    
    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        
        for tup in graph[now]:
            cost = tup[1] + dist
            if cost < distance[tup[0]]:
                distance[tup[0]] = cost
                heapq.heappush(q, [cost, tup[0]])
                trace[tup[0]] = now
                
src, dest = map(int, input().split())
dijkstra(src)
print(distance[dest])

ans = []
while src != dest:
    ans.append(dest)
    dest = trace[dest]
ans.append(src)
ans.reverse()

print(len(ans))
for n in ans:
    print(n, end=' ')
