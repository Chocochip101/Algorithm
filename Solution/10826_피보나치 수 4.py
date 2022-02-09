import sys
input = sys.stdin.readline


dp = [0 for _ in range(10001)]
N = int(input())
dp[0] = 0
dp[1] = 1
for i in range(2, N + 1):
    dp[i] = dp[i - 1] + dp[i - 2]
print(dp[N])