import sys
import heapq
input = sys.stdin.readline
INF = 987654321

V, E, P = map(int, input().split())
distance = [INF] * (V + 10)
graph = [[] for _ in range(V + 10)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

def dijkstra(src):
    q = []
    heapq.heappush(q, [0, src])
    distance[src] = 0

    while q:
        dist, now = heapq.heappop(q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, [cost, i[0]])

dijkstra(1)
OneToP = distance[P]
OneToV = distance[V]
distance = [INF] * (V + 10)
dijkstra(P)
PToV = distance[V]
if OneToP + PToV == OneToV:
    print('SAVE HIM')
else:
    print('GOOD BYE')