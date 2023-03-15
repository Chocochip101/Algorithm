import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N = int(input())
dp = [-1 for _ in range(N + 1)]
consult = [[0, 0]]

for _ in range(N):
    t, p = map(int, input().split())
    consult.append([t, p])

def solve(now):
    if now == N + 1:
        return 0
    if now > N + 1:
        return -float('inf')
    
    if dp[now] != -1:
        return dp[now]
    
    dp[now] = 0
    
    dp[now] += max(solve(now + 1), consult[now][1] + solve(now + consult[now][0]))
    return dp[now]

print(solve(1))