from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
num = list(map(int, input().split()))

l = max(num)
h = sum(num)

while l <= h:
    mid = (l + h) // 2
    cnt = 0
    tempSum = 0
    
    for i in range(N):
        if tempSum + num[i] > mid:
            tempSum = 0
            cnt += 1
        tempSum += num[i]
    
    if tempSum != 0:
        cnt += 1
    
    if cnt <= M:
        h = mid - 1
    else:
        l = mid + 1
    
    
print(l)