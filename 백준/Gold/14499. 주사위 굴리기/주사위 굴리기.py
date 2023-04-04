N, M, x, y, k = map(int, input().split())

dice = [[0 for _ in range(3)] for _ in range(4)]

# right 1, left 2, up 3, down 4
dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

board = []
for _ in range(N):
    board.append(list(map(int, input().split())))
orders = list(map(int, input().split()))


def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < M



for i in orders:

    nx = x + dx[i]
    ny = y + dy[i]
    
    if not isValid(nx, ny):
        continue
    
    if i == 1:
        # Mode Dice
        temp = dice[1][1]
        dice[1][1] = dice[1][2]
        dice[1][2] = dice[3][1]
        dice[3][1] = dice[1][0]
        dice[1][0] = temp
            
    elif i == 2:
        # Mode Dice
        temp = dice[1][1]
        dice[1][1] = dice[1][0]
        dice[1][0] = dice[3][1]
        dice[3][1] = dice[1][2]
        dice[1][2] = temp
    elif i == 3:
        # Mode Dice
        temp = dice[1][1]
        dice[1][1] = dice[0][1]
        dice[0][1] = dice[3][1]
        dice[3][1] = dice[2][1]
        dice[2][1] = temp
    elif i == 4:
        # Mode Dice
        temp = dice[1][1]
        dice[1][1] = dice[2][1]
        dice[2][1] = dice[3][1]
        dice[3][1] = dice[0][1]
        dice[0][1] = temp
    
    if board[nx][ny] == 0:
        board[nx][ny] = dice[1][1]
    else:
        dice[1][1] = board[nx][ny]
        board[nx][ny] = 0
        
    x, y = nx, ny
    print(dice[3][1])
    