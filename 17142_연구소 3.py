import sys
from itertools import combinations
from collections import deque

dx = [1,-1,0,0]
dy = [0,0,1,-1]
N, M = map(int, input().split())
Board = [list(map(int,input().split())) for _ in range(N)]
copyBoard = [[0] * N for _ in range(N)]
virus = []
for i in range(N):
    for j in range(N):
        if Board[i][j] == 2:
            virus.append([i, j])


def bfs(v):
    dist = [[-1] * N for _ in range(N)]
    q = deque()
    for i in v:
        q.append(i)
        dist[i[0]][i[1]] = 0
    res = 0
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and dist[nx][ny] == -1:
                if copyBoard[nx][ny] == 0 :
                    dist[nx][ny] = dist[x][y] + 1
                    res = max(dist[nx][ny], res)
                    q.append([nx, ny])
                elif  copyBoard[nx][ny] == 3:
                    dist[nx][ny] = dist[x][y] + 1
                    q.append([nx, ny])

    for i in range(N):
        for j in range(N):
            if dist[i][j] == -1 and Board[i][j] == 0:
                res = -987654321

    return res

ans = 987654321
for v in combinations(virus, M):
    # copy board
    for i in range(N):
        for j in range(N):
            if Board[i][j] == 2:
                if [i, j] in v:
                    copyBoard[i][j] = 2
                else:
                    copyBoard[i][j] = 3
            else:
                copyBoard[i][j] = Board[i][j]

    temp = bfs(v)
    if temp < 0:
        continue
    else:
        ans = min(ans, temp)
if ans == 987654321:
    print(-1)
else:
    print(ans)