import sys
input = sys.stdin.readline

N, A, D = map(int, input().split())
_li = list(map(int, input().split()))

max_num = max(_li)

now = A
cnt = 0
for i in range(N):
    if now == _li[i]:
        now += D
        cnt += 1
print(cnt)