import sys
input = sys.stdin.readline

N = int(input())
T = list(map(int, input().split()))
T.sort(reverse=True)

for i in range(N):
    T[i] -= N - i - 1

print(N + 1 + max(T))