N = -1
dp = []
def solve(x, y, triangle):
    if x >= N or x < y:
        return 0
    
    if dp[x][y] != -1:
        return dp[x][y]
    
    dp[x][y] = max(solve(x + 1, y, triangle), solve(x + 1, y + 1, triangle)) + triangle[x][y]
    
    return dp[x][y]
    
def solution(triangle):
    global dp, N
    N = len(triangle)
    dp = [[-1 for _ in range(i + 1)] for i in range(len(triangle))]
    return solve(0, 0, triangle)