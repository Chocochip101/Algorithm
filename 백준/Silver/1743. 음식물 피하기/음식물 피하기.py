import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

N, M, K = map(int, input().split())

board = [[-1 for _ in range(M)] for _ in range(N)]
ans = 0
temp = 0
for _ in range(K):
    a, b = map(int, input().split())
    board[a - 1][b - 1] = 1

def dfs(x, y):
    global temp
    temp += 1
    board[x][y] = -1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 1:
            dfs(nx, ny)

for i in range(N):
    for j in range(M):
        if board[i][j] == 1:
            temp = 0
            dfs(i, j)
            ans = max(temp, ans)
print(ans)