import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline


M, N = map(int, input().split())
visited = [[False for _ in range(M)] for _ in range(N)]
board = [list(map(int, input().split())) for _ in range(N)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def convertToDir(d):
    _, dd = bin(d).split('b')
    if len(dd) < 4:
        dd = '0' * (4 - len(dd)) + dd
    return dd
    
rooms = []
rooms_cord = []
rooms_connect = []
temp = 0
def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < M

def dfs(x, y, now):
    rooms_cord[now].add((x, y))
    global temp
    temp += 1
    visited[x][y] = True
    d = convertToDir(board[x][y])
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if isValid(nx, ny):
            if d[i] == '0':
                if not visited[nx][ny]:
                    dfs(nx, ny, now)
            else:
                for j in range(len(rooms) - 1):
                    if (nx, ny) in rooms_cord[j]:
                        rooms_connect[now].add(j)

           

for i in range(N):
    for j in range(M):
        if not visited[i][j]:
            temp = 0
            rooms.append(0)
            rooms_cord.append(set())
            rooms_connect.append(set())
            dfs(i, j, len(rooms) - 1)
            rooms[len(rooms) - 1] = temp
            
max_room_size = 0  
for i in range(len(rooms)):
    for j in rooms_connect[i]:
        if i != j:
            max_room_size = max(max_room_size, rooms[i] + rooms[j])
    

print(len(rooms))
print(max(rooms))
print(max_room_size)
