N = int(input())
boj = input().rstrip()

dp = [-1 for _ in range(N + 1)]

def solve(n, prev):
    if n >= N - 1:
        return 0
    if dp[n] != -1:
        return dp[n]

    dp[n] = float('inf')
    for k in range(1, N - n):
        if (prev == 'B' and boj[n + k] == 'O') or (prev == 'O' and boj[n + k] == 'J') or (prev == 'J' and boj[n + k] == 'B'):   
            dp[n] = min(dp[n], solve(n + k, boj[n + k]) + k * k)
    return dp[n]

ans = solve(0, 'B')
if ans < float('inf'):
    print(ans)
else:
    print(-1)