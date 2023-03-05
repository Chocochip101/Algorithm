import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N = int(input())
_li = list(list(map(int, input().split())) for _ in range(N))
dp = [[-1 for _ in range(501)] for _ in range(501)]

def solve(r, c):
    if r == N:
        return 0
    
    if dp[r][c] != -1:
        return dp[r][c]
    
    ret = 0
    ret = max(solve(r + 1, c) , solve(r + 1, c + 1)) + _li[r][c]
    dp[r][c] = ret
    return ret

print(solve(0, 0))