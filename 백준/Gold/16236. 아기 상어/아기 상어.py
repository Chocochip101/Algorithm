import sys
from collections import deque

N = int(input())
board = []
shark_size = 2
shark_stk = 0
sx, sy = 0, 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
for i in range(N):
    _li = list(map(int, input().split()))
    for j in range(N):
        if _li[j] == 9:
            _li[j] = 0
            sx, sy = i, j
    board.append(_li)


def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < N



ans = 0
while True:
    visited = [[-1 for _ in range(N)] for _ in range(N)]
    q = deque()
    q.append([sx, sy])
    visited[sx][sy] = 0
    cand = list()
    flag = False
    while q:
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if isValid(nx, ny) and visited[nx][ny] == -1:
                # 자신보다 큰 물고기
                if board[nx][ny] > shark_size:
                    continue
                
                # 자신이랑 같은 물고기
                elif board[nx][ny] == shark_size or board[nx][ny] == 0:
                    q.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1
                # 먹을 수 있는 물고기
                else:
                    flag = True
                    visited[nx][ny] = visited[x][y] + 1
                    cand.append((visited[nx][ny], nx, ny))
    if not flag:
        break
    else:
        cand.sort()
        ans += cand[0][0]
        sx, sy = cand[0][1], cand[0][2]
        shark_stk += 1
        if shark_stk == shark_size:
            shark_size += 1
            shark_stk = 0
        board[sx][sy] = 0

    
print(ans)