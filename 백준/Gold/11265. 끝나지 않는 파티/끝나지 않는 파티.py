import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))

for t in range(N):
    for i in range(N):
        for j in range(N):
            graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j])
            
for _ in range(M):
    A, B, C = map(int, input().split())
    if graph[A - 1][B - 1] <= C:
        print("Enjoy other party")
    else:
        print("Stay here")