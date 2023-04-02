import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline


N = int(input())


loss_health = list(map(int, input().split()))
smile = list(map(int, input().split()))
dp = [[-1 for _ in range(101)] for _ in range(N)]

def solve(idx, res_h):
    if idx == N:
        return 0
    
    if dp[idx][res_h] != -1:
        return dp[idx][res_h]

    dp[idx][res_h] = max(dp[idx][res_h], solve(idx + 1, res_h))
    
    if res_h - loss_health[idx] > 0:
        dp[idx][res_h] = max(dp[idx][res_h], solve(idx + 1, res_h - loss_health[idx]) + smile[idx])
    
    return dp[idx][res_h]
print(solve(0, 100))