import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline


N = int(input())

h = list(map(int, input().split()))
total = sum(h)
twos = 0
for i in range(N):
    twos += h[i] // 2
if total % 3 == 0 and twos >= total / 3:
    print("YES")
else:
    print("NO")