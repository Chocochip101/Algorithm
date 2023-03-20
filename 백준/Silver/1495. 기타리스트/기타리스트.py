import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
N, S, M = map(int, input().split())
vol = list(map(int, input().split()))
dp = [[-1 for _ in range(M + 1)] for _ in range(N + 1)]

def solve(i, now):
    if i == N:
        return now
    
    if dp[i][now] != -1:
        return dp[i][now]
    
    dp[i][now] = -float('inf')
    if now + vol[i] <= M:
        dp[i][now] = max(dp[i][now], solve(i + 1, now + vol[i]))
        
    if now - vol[i] >= 0:
        dp[i][now] = max(dp[i][now], solve(i + 1, now - vol[i]))
    return dp[i][now]

if solve(0, S) == -float('inf'):
    print(-1)
else:
    print(solve(0, S))