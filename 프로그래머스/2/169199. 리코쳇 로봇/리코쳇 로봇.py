from collections import deque

rx, ry = 0, 0
gx, gy = 0, 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def solution(board):
    global rx, ry, gx, gy
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 'R':
                rx = i
                ry = j
            if board[i][j] == 'G':
                gx = i
                gy = j            
    return bfs(board)

def bfs(board):
    dist = [[-1 for _ in range(len(board[0]))] for _ in range(len(board))]
    dist[rx][ry] = 0
    q = deque()
    q.append([rx, ry])

    while q:
        x, y = q.popleft()
        if board[x][y] == 'G':
            break
        for i in range(4):
            nx, ny = move(x, y, i, board)
            if dist[nx][ny] != -1:
                continue
            dist[nx][ny] = dist[x][y] + 1
            q.append([nx, ny])
    return dist[gx][gy]

def move(x, y, direction, board):
    nx, ny = x, y
    while isValid(nx, ny, board) and board[nx][ny] != 'D':
        nx = nx + dx[direction]
        ny = ny + dy[direction]
    return nx - dx[direction], ny - dy[direction]

def isValid(nx, ny, board):
    return 0 <= nx < len(board) and 0 <= ny < len(board[0])