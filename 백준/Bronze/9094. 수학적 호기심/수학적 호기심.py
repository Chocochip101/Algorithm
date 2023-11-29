import sys
input = sys.stdin.readline
def solve(n, m):
    cnt = 0
    for a in range(1, n):
        for b in range(a + 1, n):
            if (a * a + b * b + m) / (a * b) == (a * a + b * b + m) // (a * b):
                cnt += 1
    return cnt

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    print(solve(n, m))
    
