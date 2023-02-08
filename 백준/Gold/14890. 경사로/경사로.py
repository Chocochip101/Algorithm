import sys
import copy
input = sys.stdin.readline


N, L = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

def isValid(nx, ny):
    return 0 <= nx < N and 0 <= ny < N

def canGoRow(x):
    bridge = set()
    for i in range(1, N):
        if board[x][i - 1] != board[x][i]:

            if abs(board[x][i - 1] - board[x][i]) != 1:
                return False
            
            if board[x][i - 1] > board[x][i]:
                for j in range(L):
                    # 갈 수 없는 경우
                    if not isValid(x, i + j):
                        return False
                    
                    # 이미 다리가 있는 경우
                    if i + j in bridge:
                        return False
                    
                    # 높이 차가 다른 경우
                    if board[x][i + j] != board[x][i]:
                        return False
                        
                # 경사로 설치 가능
                for j in range(L):
                    bridge.add(i + j)
                
            if board[x][i - 1] < board[x][i]:
                for j in range(L):

                    # 갈 수 없는 경우
                    if not isValid(x, i - 1 - j):
                        return False
                    
                    # 이미 다리가 있는 경우
                    if i - 1 - j in bridge:
                        return False
                    
                    # 높이 차가 다른 경우
                    if board[x][i - 1 - j] != board[x][i - 1]:
                        return False
                        
                # 경사로 설치 가능
                for j in range(L):
                    bridge.add(i - 1 - j)
            
    return True

def canGoCol(y):
    bridge = set()
    for j in range(1, N):
        if board[j - 1][y] != board[j][y]:
            if abs(board[j - 1][y] - board[j][y]) != 1:
                return False
            
            if board[j - 1][y] > board[j][y]:
                for i in range(L):
                    # 갈 수 없는 경우
                    if not isValid(j + i, y):
                        return False
                    
                    # 이미 다리가 있는 경우
                    if j + i in bridge:
                        return False
                    
                    # 높이 차가 다른 경우
                    if board[j + i][y] != board[j][y]:
                        return False
                        
                # 경사로 설치 가능
                for i in range(L):
                    bridge.add(i + j)
                
            if board[j - 1][y] < board[j][y]:
                for i in range(L):
                    # 갈 수 없는 경우
                    if not isValid(j - 1 - i, y):
                        return False
                    
                    # 이미 다리가 있는 경우
                    if j - 1 - i in bridge:
                        return False
                    
                    # 높이 차가 다른 경우
                    if board[j - 1 - i][y] != board[j - 1][y]:
                        return False
                        
                # 경사로 설치 가능
                for i in range(L):
                    bridge.add(j - 1 - i)
    return True

ans = 0
for i in range(N):
    if canGoRow(i):
        ans += 1
    if canGoCol( i):
        ans += 1
        
print(ans)