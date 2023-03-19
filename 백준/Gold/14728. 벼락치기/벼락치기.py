import sys

N, T = map(int, input().split())
problem = []
dp = [[-1 for _ in range(T + 1)] for _ in range(N)]

for _ in range(N):
    K, S = map(int, input().split())
    problem.append([K, S])
    
def solve(idx, cost):
    if idx < 0 or cost < 0:
        return 0
    
    if dp[idx][cost] != -1:
        return dp[idx][cost]
    
    # idx 선택
    if cost - problem[idx][0] >= 0:
        dp[idx][cost] = max(dp[idx][cost], solve(idx - 1, cost - problem[idx][0]) + problem[idx][1])
    
    # idx 선택 안함
    dp[idx][cost] = max(dp[idx][cost], solve(idx - 1, cost))
    
    return dp[idx][cost]
            

print(solve(N - 1, T))