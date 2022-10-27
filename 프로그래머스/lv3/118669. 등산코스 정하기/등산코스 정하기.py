import heapq
INF = int(1e9)

def solution(n, paths, gates, summits):
    summits.sort()
    summits_set = set(summits)
    graph = [[] for _ in range(n + 1)]
    for i, j, w in paths:
        graph[i].append([j, w])
        graph[j].append([i, w])

    pq = []
    distance = [INF] * (n + 1)

    for gate in gates:
        heapq.heappush(pq, (0, gate))
        distance[gate] = 0

    while pq:
        intensity, now = heapq.heappop(pq)

        if now in summits_set or intensity > distance[now]:
            continue

        for next, cost in graph[now]:
            new_intensity = max(intensity, cost)
            if new_intensity < distance[next]:
                distance[next] = new_intensity
                heapq.heappush(pq, (new_intensity, next))

    result = [0, INF]

    for summit in summits:
        if distance[summit] < result[1]:
            result[0] = summit
            result[1] = distance[summit]
    return result
