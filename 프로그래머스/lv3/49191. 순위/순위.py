from collections import deque

def solution(n, results):

    graph = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    for a, b in results:
        graph[a][b] = 1
        
    for t in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if graph[i][t] == 1 and graph[t][j] == 1:
                    graph[i][j] = 1
    ans = 0
    for i in range(1, n + 1):
        row_s = sum(graph[i])
        col_s = 0
        for j in range(1, n + 1):
            col_s += graph[j][i]
        if row_s + col_s == n - 1:
            ans += 1
        
    return ans