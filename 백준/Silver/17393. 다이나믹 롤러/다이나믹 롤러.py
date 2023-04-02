import sys
import bisect
input = sys.stdin.readline


N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))


for i in range(N):
    idx = bisect.bisect_right(B, A[i])
    if idx - i - 1 > 0:
        print(idx - i - 1, end= ' ')
    else:
        print(0, end=' ')

