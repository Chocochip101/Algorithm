from collections import deque

        
def solution(n, edge):
    dist = [-1 for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]
    
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    
    q = deque()
    q.append(1)
    
    dist[1] = 1
    
    while q:
        now = q.popleft()
        for next in graph[now]:
            if dist[next] == -1:
                dist[next] = dist[now] + 1
                q.append(next)
    mDist = max(dist)
    answer = 0
    for i in range(1, n + 1):
        if mDist == dist[i]:
            answer += 1

    return answer if answer > 1 else 1