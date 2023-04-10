import heapq
import sys
input = sys.stdin.readline
N, M = map(int, input().split())

graph = [[] for _ in range(N)]
ward = list(map(int, input().split()))
ward[-1] = 0
q = []
for _ in range(M):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))
    graph[b].append((a, t))
    
    
distance = [float('inf') for _ in range(N)]

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
            if ward[tup[0]] == 0 and cost < distance[tup[0]]:
                distance[tup[0]] = cost
                heapq.heappush(q, [cost, tup[0]])
                
dijkstra(0)

if distance[-1] < float('inf'):
    print(distance[-1])
else:
    print(-1)