import sys
input = sys.stdin.readline

R, C, W = map(int, input().split())
dp = [[-1 for _ in range(32)] for _ in range(32)]

dp[0][0] = 1

for row in range(1, 32):
    for col in range(row + 1):
        if col == row:
            dp[row][col] = dp[row - 1][col - 1]
        elif col == 0:
            dp[row][col] = dp[row - 1][col]
        else:
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col]

total = 0
for r in range(R - 1, R - 1 + W):
    for c in range(r - R + 2):
        total += dp[r][C - 1 + c]
print(total)