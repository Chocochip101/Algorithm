import sys
input = sys.stdin.readline

N, M = map(int, input().split())

names = []
for _ in range(N):
    names.append(input().split())

names.sort(key= lambda x: int(x[1]))

for _ in range(M):
    a = int(input())
    left = 0
    right = N
    res = 0
    while left < right:
        mid = (left + right) // 2
        if int(names[mid][1]) >= a:
            res = names[mid][0]
            right = mid
        else:
            left = mid + 1
    print(res)