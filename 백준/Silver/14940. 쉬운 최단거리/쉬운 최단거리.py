from collections import deque
N, M = map(int, input().split())

board = []
distance = [[-1 for _ in range(M)] for _ in range(N)]

sx, sy = 0, 0
for i in range(N):
    _li = list(map(int, input().split()))
    for j in range(M):
        if _li[j] == 2:
            sx, sy = i, j
    board.append(_li)
    

q = deque()
q.append([sx, sy])
distance[sx][sy] = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

while q:
    x, y = q.popleft()
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0<= nx < N and 0<= ny < M:
            if board[nx][ny] == 1 and distance[nx][ny] == -1:
                distance[nx][ny] = distance[x][y] + 1
                q.append([nx, ny])
    
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            print(0, end=" ")
        else:
            print(distance[i][j], end=" ")
    print()
