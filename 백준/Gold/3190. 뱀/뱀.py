import sys
from collections import deque
# R, D, L, U
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


N = int(input())
K = int(input())
# Apple: 1
board = [[ 0 for _ in range(N)] for _ in range(N)]

for _ in range(K):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    board[a][b] = 1

L = int(input())
q = deque()
for _ in range(L):
    X, C = input().split()
    q.append([X, C])

def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < N


ans = 0
s_d = 0

snake_coords = deque()
snake_coords.append([0, 0])

while True:
    

    if len(q) != 0 and ans == int(q[0][0]):
        if q[0][1] == 'L':
            s_d -= 1
            if s_d == -1:
                s_d = 3
        else:
            s_d += 1
            if s_d == 4:
                s_d = 0
        q.popleft()
        
    x, y = snake_coords[0]
    nx, ny = x + dx[s_d], y + dy[s_d]
    if not isValid(nx, ny):
        break
    if [nx, ny] in snake_coords:
        break
    
    if board[nx][ny] == 1:
        board[nx][ny] = 0
        snake_coords.appendleft([nx, ny])
    else:
        snake_coords.pop()
        snake_coords.appendleft([nx, ny])
    ans += 1
    

print(ans + 1)