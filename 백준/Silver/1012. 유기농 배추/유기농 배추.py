import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
board = [[-1 for _ in range(51)] for _ in range(51)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y, N, M):
    global board
    board[x][y] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 1:
            dfs(nx, ny, N, M)

T = int(input())

for _ in range(T):
    N, M, K = map(int, input().split())

    board = [[-1 for _ in range(M)] for _ in range(N)]
    
    for _ in range(K):
        x, y = map(int, input().split())
        board[x][y] = 1
    
    cnt = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                cnt += 1
                dfs(i, j, N, M)
    print(cnt)