import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline
DIV = 1000000009
MAX = 1001

cache = [ [-1 for _ in range(MAX)] for _ in range(MAX)]

def solve(n, m):
    if n == 0:
        return 1

    if cache[n][m] != -1:
        return cache[n][m]
    
    ret = 0

    if n >= 1 and m > 0:
        ret += solve(n - 1, m - 1)
        ret %= DIV
    
    if n >= 2 and m > 0:
        ret += solve(n - 2, m - 1)
        ret %= DIV
    
    if n >= 3 and m > 0:
        ret += solve(n - 3, m - 1)
        ret %= DIV
    
    cache[n][m] = ret
    return ret


T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    print(solve(n, m))