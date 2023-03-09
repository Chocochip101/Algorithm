import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(list(map(int, input().split())) for _ in range(N))
R = [0 for _ in range(N)]
C = [0 for _ in range(M)]
result = 0

for i in range(N):
    for j in range(M):
        if (i == 0 and j == 0) or (i == 0  and j == M - 1) or (i == N - 1 and j == 0) or (i == N - 1 and j == M - 1):
            R[i] += A[i][j]
            C[j] += A[i][j]
            result += A[i][j]
        elif i == 0 or i == N - 1 or j == 0 or j == M - 1:
            R[i] += 2 * A[i][j]
            C[j] += 2 * A[i][j]
            result += 2 * A[i][j]
        else:
            R[i] += 4 * A[i][j]
            C[j] += 4 * A[i][j]
            result += 4 * A[i][j]
            
area = -float('inf')
for i in range(1, N - 1):
    area = max(area, result - (R[i] // 2) + R[0])
    area = max(area, result - R[i] // 2 + R[N - 1])
for i in range(1, M - 1):
    area = max(area, result - C[i] // 2 + C[0])
    area = max(area, result - C[i] // 2 + C[M - 1])

result = max(result, area)
print(result)