import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
parSum = [0 for _ in range(N)]
parSum[0] = A[0]

for i in range(1, N):
    parSum[i] = parSum[i - 1] + A[i]

res = [0 for _ in range(M)]
answer = 0
for i in range(N):
    if parSum[i] % M == 0:
        answer += 1
    res[parSum[i] % M] += 1

for i in range(M):
    if res[i] > 0:
        answer += (res[i] * (res[i] - 1)) // 2
print(answer)