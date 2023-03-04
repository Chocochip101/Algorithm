import sys
input = sys.stdin.readline

dp = [[-1 for _ in range(15)] for _ in range(15)]
def solve(k, n):
    if k == 0:
        return n
    if dp[k][n] != -1:
        return dp[k][n]
    res = 0
    for i in range(1, n + 1):
        res += solve(k - 1, i)
    dp[k][n] = res    
    return res

T = int(input())
for _ in range(T):
    K = int(input())
    N = int(input())
    print(solve(K, N))