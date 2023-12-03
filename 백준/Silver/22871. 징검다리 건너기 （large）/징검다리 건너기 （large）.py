import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

dp = [float('inf') for _ in range(N)]
dp[0] = 0

for j in range(1, N):
    for i in range(j):
        dp[j] = min(dp[j], max(dp[i], (j - i) * (1 + abs(A[i] - A[j]))))

print(dp[N - 1])