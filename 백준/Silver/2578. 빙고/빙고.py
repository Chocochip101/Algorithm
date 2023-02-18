bingo = list(list(map(int, input().split())) for _ in range(5))
ans = list(list(map(int, input().split())) for _ in range(5))

def checkBingo():
    bingos = 0
    
    for i in range(5):
        cnt = 0
        for j in range(5):
            if bingo[i][j] == -1:
                cnt += 1
        if cnt == 5:
            bingos += 1
           
    for i in range(5):
        cnt = 0
        for j in range(5):
            if bingo[j][i] == -1:
                cnt += 1
        if cnt == 5:
            bingos += 1 
            
    cnt = 0
    for i in range(5):
        if bingo[i][i] == -1:
                cnt += 1
    if cnt == 5:
            bingos += 1 
    
    cnt = 0
    for i in range(5):
        if bingo[i][5 - i - 1] == -1:
                cnt += 1
    if cnt == 5:
            bingos += 1 
    
    return bingos
        


def findAns(num):
    for i in range(5):
        for j in range(5):
            if bingo[i][j] == num:
                bingo[i][j] = -1
                return [i, j]
                

cnt = 0
for i in range(5):
    for j in range(5):
        cnt += 1
        [x, y] = findAns(ans[i][j])
        if checkBingo() >= 3:
            print(cnt)
            exit()