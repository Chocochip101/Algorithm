import sys
sys.setrecursionlimit(10**8)
from collections import deque
input = sys.stdin.readline
MAX = 200000

R, C = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
T = int(input())

def solve(x, y):
    temp = []
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            temp.append(board[i][j])
    temp.sort()
    return temp[4]

res = 0
for i in range(R - 2):
    for j in range(C - 2):
        if solve(i, j) >= T:
            res += 1
print(res)