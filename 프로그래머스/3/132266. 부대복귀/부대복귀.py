from collections import deque

def solution(n, roads, sources, destination):
    graph = [[] for _ in range(n + 1)]
    dist = [-1 for _ in range(n + 1)]
    q = deque()
    
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)
    
    answer = []
    q.append(destination)
    dist[destination] = 0
    
    while q:
        now = q.popleft()
        for nex in graph[now]:
            if dist[nex] == -1:
                dist[nex] = dist[now] + 1
                q.append(nex)
    for s in sources:
        answer.append(dist[s])
    return answer