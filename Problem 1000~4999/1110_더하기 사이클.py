import sys
input = sys.stdin.readline
def refactor(n):
    a = n // 10
    b = n % 10
    c = (a + b) % 10
    return (b * 10) + c

N = int(input())
Target = N
ans = 0
while 1:
    ans += 1
    N = refactor(N)
    if Target == N:
        break

print(ans)