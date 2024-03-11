from collections import deque
visited = []
def solution(maps):
    global visited
    visited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    
    answer = []
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] != 'X' and not visited[i][j]:
                answer.append(bfs(i, j, maps))
                print()
    
    if len(answer) == 0:
        answer.append(-1)
    answer.sort()
    return answer

def bfs(i, j, maps):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    
    q = deque()
    ret = 0
    q.append([i, j])
    visited[i][j] = True
    while q:
        x, y = q.popleft()
        print(x, y, maps[x][y])
        ret += int(maps[x][y])
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if isValid(nx, ny, maps) and not visited[nx][ny] and maps[nx][ny] != 'X':
                q.append([nx, ny])
                visited[nx][ny] = True
    return ret

def isValid(x, y, maps):
    return 0 <= x < len(maps) and 0 <= y < len(maps[0])