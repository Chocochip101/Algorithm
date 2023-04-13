import sys
sys.setrecursionlimit(10**8)
T = int(input())
MAX = 10002
dp = [[-1 for _ in range(4)] for _ in range(MAX)]

def solve(n, k):
    if (n == 1 and k == 1) or (n == 2 and k == 1) or (n == 2 and k == 2) or (n == 3 and k == 1)  or (n == 3 and k == 2)  or (n == 3 and k == 3):
        return 1
    if n < 1:
        return 0
    if dp[n][k] != -1:
        return dp[n][k]
    
    if k == 1:
        dp[n][k] = solve(n - 1, k)
    elif k == 2:
        dp[n][k] = solve(n - 2, 1) + solve(n - 2, 2)
    elif k == 3:
        dp[n][k] = solve(n - 3, 1) + solve(n - 3, 2) + solve(n - 3, 3) 
    return dp[n][k]

for _ in range(T):

    dp[1][1] = 1 
    dp[2][1] = 1 
    dp[2][2] = 1 
    dp[3][1] = 1 
    dp[3][2] = 1 
    dp[3][3] = 1
    
    N = int(input())
    print(solve(N, 1) + solve(N, 2) + solve(N, 3))

    