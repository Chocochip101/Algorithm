import sys

N, M = map(int, input().split())
nums = list(map(int, input().split()))

start = 0
end = 0
parSum = 0
res = 0

while end <= N:

    if parSum < M:
        if end < N:
            parSum += nums[end]
        end += 1
    else:
        if start < N:
            parSum -= nums[start]
        start += 1
    
    if parSum == M:
        res += 1

print(res)