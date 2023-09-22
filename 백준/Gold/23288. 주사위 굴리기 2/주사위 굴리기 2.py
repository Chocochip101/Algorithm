from collections import defaultdict, deque

N, M, K = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, input().split())))
    
score = 0
dice_x = 0
dice_y = 0

# 동, 서, 남, 북
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

dice = defaultdict()
dice['TOP'] = 1
dice['BUTTOM'] = 6
dice['EAST'] = 3
dice['WEST'] = 4
dice['NORTH'] = 2
dice['SOUTH'] = 5

direction = 0

def rotateDirection():
    global direction
    if direction == 0:
        direction = 2
    elif direction == 3:
        direction = 0
    elif direction == 1:
        direction = 3
    elif direction == 2:
        direction = 1

def rotateDirectionOpposite():
    global direction
    if direction == 0:
        direction = 3
    elif direction == 3:
        direction = 1
    elif direction == 1:
        direction = 2
    elif direction == 2:
        direction = 0

def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < M

def C(x, y):
    q = deque()
    q.append([x, y])
    visited = [[False for _ in range(M)] for _ in range(N)]
    visited[x][y] = True
    
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if isValid(nx, ny) and (not visited[nx][ny]) and board[x][y] == board[nx][ny]:
                visited[nx][ny] = True
                cnt += 1
                q.append([nx, ny])
    return cnt

def moveDice():
    global direction
    if direction == 0:
        TOP = dice['TOP']
        BUTTOM = dice['BUTTOM']
        EAST = dice['EAST']
        WEST = dice['WEST']
        dice['TOP'] = WEST
        dice['BUTTOM'] = EAST
        dice['EAST'] = TOP
        dice['WEST'] = BUTTOM
    elif direction == 1:
        TOP = dice['TOP']
        BUTTOM = dice['BUTTOM']
        EAST = dice['EAST']
        WEST = dice['WEST']
        dice['TOP'] = EAST
        dice['BUTTOM'] = WEST
        dice['EAST'] = BUTTOM
        dice['WEST'] = TOP
    elif direction == 2:
        TOP = dice['TOP']
        BUTTOM = dice['BUTTOM']
        SOUTH = dice['SOUTH']
        NORTH = dice['NORTH']
        dice['TOP'] = NORTH
        dice['BUTTOM'] = SOUTH
        dice['SOUTH'] = TOP
        dice['NORTH'] = BUTTOM
    elif direction == 3:
        TOP = dice['TOP']
        BUTTOM = dice['BUTTOM']
        SOUTH = dice['SOUTH']
        NORTH = dice['NORTH']
        dice['TOP'] = SOUTH
        dice['BUTTOM'] = NORTH
        dice['SOUTH'] = BUTTOM
        dice['NORTH'] = TOP

def reverseDirection():
    global direction
    if direction == 0:
        direction = 1
    elif direction == 1:
        direction = 0
    elif direction == 2:
        direction = 3
    elif direction == 3:
        direction = 2

while K > 0:
    K -= 1
    nx = dice_x + dx[direction]
    ny = dice_y + dy[direction]
    
    if not isValid(nx, ny):
        reverseDirection()
        nx = dice_x + dx[direction]
        ny = dice_y + dy[direction]
    moveDice()
    B = board[nx][ny]
    score += C(nx, ny) * B
    
    A = dice['BUTTOM']
    if A > B:
        rotateDirection()
    elif A < B:
        rotateDirectionOpposite()
    dice_x = nx
    dice_y = ny

print(score)    