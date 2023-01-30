import sys
from itertools import combinations
input = sys.stdin.readline
MAX = 987654321

N = int(input())

costs = list(map(int, input().split()))
dp = [-1 for _ in range(N + 1)]

def solve(c):
    if c == 0:
        return 0
    
    if dp[c] != -1:
        return dp[c]
    
    ret = MAX
    
    for i in range(1, c + 1):
        ret = min(ret, solve(c - i) + costs[i - 1])
        
    dp[c] = ret
    return ret

print(solve(N))