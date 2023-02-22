
def dfs(node, visited, N, computers):
    global cnt
    visited[node] = True
    for next in range(N):
        if (not visited[next]) and (computers[node][next] == 1) and (node != next):
            dfs(next, visited, N, computers)

def solution(n, computers):
    global cnt
    answer = 0
    visited = [False for _ in range(n + 1)]
    for i in range(n):
        if not visited[i]:
            dfs(i, visited, n, computers)
            answer += 1
    return answer