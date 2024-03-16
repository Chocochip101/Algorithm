def solution(board):
    Ocnt = 0
    Xcnt = 0
    for row in board:
        for p in row:
            if p == "O":
                Ocnt += 1
            if p == "X":
                Xcnt += 1

    madeO, madeX = made(board)
    print(madeO, madeX)
    if (madeO == 0 and madeX == 0) and (Ocnt == Xcnt or Ocnt == Xcnt + 1):
        return 1
    if (madeO == 1 and madeX == 0) and ((Ocnt == 4 and Xcnt == 3) or (Ocnt == 3 and Xcnt == 2) or (Ocnt == 3 and Xcnt == 2) or (Ocnt == Xcnt + 1)):
        return 1
    if (madeO == 0 and madeX == 1) and (Ocnt == Xcnt):
        return 1
    if (madeO == 2 and madeX == 0) and (Ocnt == 5 and Xcnt == 4):
        return 1
    return 0

def made(board):

    Opoints = 0
    Xpoints = 0
    for i in range(3):
        if board[i][0] == board[i][1] and board[i][1] == board[i][2]:
            if board[i][0] == "O":
                Opoints += 1
            if board[i][0] == "X":
                Xpoints += 1
    for j in range(3):
        if board[0][j] == board[1][j] and board[1][j] == board[2][j]:
            if board[0][j] == "O":
                Opoints += 1
            if board[0][j] == "X":
                Xpoints += 1        
    if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
            if board[0][0] == "O":
                Opoints += 1
            if board[0][0] == "X":
                Xpoints += 1 
    if board[0][2] == board[1][1] and board[1][1] == board[2][0] :
            if board[0][2] == "O":
                Opoints += 1
            if board[0][2] == "X":
                Xpoints += 1

    return Opoints, Xpoints