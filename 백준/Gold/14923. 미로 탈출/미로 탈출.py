import sys
input = sys.stdin.readline
from collections import deque


def bfs():
    queue = deque()
    queue.append([s_x-1,s_y-1,0,1])
    visited = [[[False for _ in range(M)] for _ in range(N)] for _ in range(2)]
    visited[1][s_x-1][s_y-1] = True
    while queue:
        x,y,time,key = queue.popleft()
        if x==t_x-1 and y==t_y-1:
            return time
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if 0<=nx<N and 0<=ny<M:
                if key:
                    if not maze[nx][ny]:
                        if not visited[1][nx][ny]:
                            visited[1][nx][ny] = True
                            queue.append([nx,ny,time+1,key])
                    elif maze[nx][ny]:
                        if not visited[0][nx][ny]:
                            visited[0][nx][ny] = True
                            key = 0
                            queue.append([nx,ny,time+1,key])
                            key = 1
                elif not key:
                    if not visited[0][nx][ny]:
                        if not maze[nx][ny]:
                            visited[0][nx][ny] = True
                            queue.append([nx,ny,time+1,key])
    return -1

N, M = map(int, input().split())
s_x,s_y = map(int, input().split())
t_x,t_y = map(int, input().split())
maze = [list(map(int, input().split())) for _ in range(N)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]
print(bfs())