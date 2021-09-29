import sys
#
sys.setrecursionlimit(1000000)
m, n = map(int, input().split())
graph = []

for _ in range(m):
  graph.append(list(map(int, input().split())))

dist = [[-1] * n for _ in range(m)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y):
  # 기저 사례
  if x == 0 and y == 0:
    return 1

  if dist[x][y] == -1:
    dist[x][y] = 0
    for i in range(4):
      nx, ny = x + dx[i], y + dy[i]
      if 0 <= nx < m and  0 <= ny < n:
        if graph[x][y] < graph[nx][ny]:
          dist[x][y] += dfs(nx, ny)
  return dist[x][y]

print(dfs(m - 1, n - 1))