import sys
input = sys.stdin.readline
from collections import deque
from itertools import combinations
import copy
sys.setrecursionlimit(10 ** 9)

N, M = map(int, input().split())
safe_point = []
virus = []
board = []
for i in range(N):
    _li = list(map(int, input().split()))
    for j in range(M):
        if _li[j] == 0:
            safe_point.append([i, j])
        elif _li[j] == 2:
            virus.append([i, j])
    board.append(_li)

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]


res = 0
def bfs(bb):
    tempBoard = copy.deepcopy(bb)
    q = deque(virus)
        

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and tempBoard[nx][ny] == 0:
                tempBoard[nx][ny] = 2
                q.append([nx, ny])
    
    cnt = 0
    for i in range(N):
        for j in range(M):
            if tempBoard[i][j] == 0:
                cnt += 1
    global res 
    res = max(res, cnt)
                

for points in combinations(safe_point, 3):
    board[points[0][0]][points[0][1]] = 1
    board[points[1][0]][points[1][1]] = 1
    board[points[2][0]][points[2][1]] = 1

    bfs(board)
    board[points[0][0]][points[0][1]] = 0
    board[points[1][0]][points[1][1]] = 0
    board[points[2][0]][points[2][1]] = 0
print(res)