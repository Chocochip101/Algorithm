import sys
sys.setrecursionlimit(10**9)
# src -> dst
dists = {
    0: [1, 7, 6, 7, 5, 4, 5, 3, 2, 3],
    1: [7, 1, 2, 4, 2, 3, 5, 4, 5, 6],
    2: [6, 2, 1, 2, 3, 2, 3, 5, 4, 5],
    3: [7, 4, 2, 1, 5, 3, 2, 6, 5, 4],
    4: [5, 2, 3, 5, 1, 2, 4, 2, 3, 5],
    5: [4, 3, 2, 3, 2, 1, 2, 3, 2, 3],
    6: [5, 5, 3, 2, 4, 2, 1, 5, 3, 2],
    7: [3, 4, 5, 6, 2, 3, 5, 1, 2, 4],
    8: [2, 5, 4, 5, 3, 2, 3, 2, 1, 2],
    9: [3, 6, 5, 4, 5, 3, 2, 4, 2, 1]
}

dp = [[[-1 for _ in range(11)] for _ in range(11)] for _ in range(100001)]

def solution(numbers):
    return solve(numbers, 0, 4, 6) 

def solve(numbers, idx, left, right):
    if idx >= len(numbers):
        return 0
    if dp[idx][left][right] != -1:
        return dp[idx][left][right]
    toPush = stringToIdx(numbers[idx])
    if toPush == left:
        dp[idx][left][right] = solve(numbers, idx + 1, toPush, right) + 1
        return dp[idx][left][right]
    if toPush == right:
        dp[idx][left][right] = solve(numbers, idx + 1, left, toPush) + 1
        return dp[idx][left][right]
    dp[idx][left][right] = min(solve(numbers, idx + 1, toPush, right) + dists[left][toPush], solve(numbers, idx + 1, left, toPush) + dists[right][toPush])
    return dp[idx][left][right]

def stringToIdx(c):
    return int(c)
    