N = int(input())
P = list(map(int, input().split()))

P.sort()

answer = 0
for i in range(N):
    answer +=  P[i] * (N - i)
print(answer)