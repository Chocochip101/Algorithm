import sys
N, M = map(int, input().split())

A = []
for _ in range(N):
    A.append(input().rstrip())
B = []  
for _ in range(N):
    B.append(input().rstrip())

res = 0
for i in range(N - 2):
    for j in range(M - 2):
        if A[i][j] != B[i][j]:
            res += 1
            for k in range(3):
                for l in range(3):
                    if B[i + k][j + l] == '0':
                        B[i + k] = B[i + k][:j + l] + '1' + B[i + k][j + l + 1:]
                    else:
                        B[i + k] = B[i + k][:j + l] + '0' + B[i + k][j + l + 1:]

flag = False
for i in range(N):
    for j in range(M):
        if A[i][j] != B[i][j]:
            flag = True
            break
if flag:
    print(-1)
else:
    print(res)