import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)

R, C, K = map(int, input().split())

board = []
for _ in range(R):
    board.append(input().rstrip())
    
visited = [[False for _ in range(C)] for _ in range(R)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def isValid(x, y):
    return 0 <= x < R and 0 <= y < C

res = 0

def dfs(x, y, dist):
    if x == 0 and y == C - 1 and dist == K:
        global res
        res += 1
        return
    visited[x][y] = True
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if isValid(nx, ny) and board[nx][ny] != 'T' and (not visited[nx][ny]):
            dfs(nx, ny, dist + 1)
    visited[x][y] = False
dfs(R - 1, 0, 1)
print(res)