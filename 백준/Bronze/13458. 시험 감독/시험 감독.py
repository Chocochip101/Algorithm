import math

N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())

res = 0
for i in range(N):
    A[i] -= B
    res += 1
    if A[i] > 0:
        res += math.ceil(A[i] / C)
print(res)