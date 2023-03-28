import sys
input = sys.stdin.readline
N, M = map(int, input().split())


T = []
for _ in range(N):
    T.append(int(input()))

l = 0
h = min(T) * M
min_time = h
while l + 1 < h:
    mid = (l + h) // 2
    
    cnt = 0
    for i in range(N):
        cnt += (mid // T[i])
        
    if cnt >= M:
        min_time = min(mid, min_time)
        h = mid
    else:
        l = mid

print(min_time)