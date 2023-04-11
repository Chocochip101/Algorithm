MOD = 1000000007

dp = []
puddle = []
def solve(x, y, n, m):    
    if x == n - 1 and y == m - 1:
        return 1
    
    if dp[x][y] != -1:
        return dp[x][y]
    
    dp[x][y] = 0
    
    if x + 1 <= n - 1 and [x + 1, y] not in puddle:
        dp[x][y] += solve(x + 1, y, n, m) % MOD
    if y + 1 <= m - 1 and [x, y + 1] not in puddle:
        dp[x][y] += solve(x, y + 1, n, m) % MOD

    return dp[x][y] % MOD

def solution(m, n, puddles):
    global dp, puddle
    puddle = puddles
    
    for c in puddle:
        c[0], c[1] = c[1], c[0]
        c[0] -= 1
        c[1] -= 1
        
    dp = [[-1 for _ in range(m)] for _ in range(n)]
    ans = solve(0, 0, n, m)
    print(dp)
    return ans