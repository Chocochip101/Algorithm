import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

N = int(input())
num = list(map(int, input().split()))
dp = [-1 for _ in range(N)]


def solve(idx):
    
    if dp[idx] != -1:
        return dp[idx]
    
    res = 0
    for i in range(idx + 1, N):
        if idx == -1 or num[idx] < num[i]:
            res = max(solve(i) + 1, res)
    dp[idx] = res
    return dp[idx]
            

print(solve(-1))