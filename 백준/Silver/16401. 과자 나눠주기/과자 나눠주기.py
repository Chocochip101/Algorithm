import sys
input = sys.stdin.readline

M, N = map(int, input().split())
candies = list(map(int, input().split()))

left = 0
right = max(candies) + 1

if M > sum(candies):
    print(0)
    exit()

res = 0
while left <= right:
    mid = (left + right) // 2
    ret = 0
    for candy in candies:
        ret += candy // mid
        
    if ret < M:
        right = mid - 1
    else:
        res = max(mid, res)
        left = mid + 1
print(res)