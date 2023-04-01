import sys
import bisect
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
nums.sort()

total = float('inf')
res = [0, 0, 0]

for i in range(N - 2):
    l, r = i + 1, N - 1
    while l < r:
        par_sum = nums[i] + nums[l] + nums[r]
        if total > abs(par_sum):
            total = abs(par_sum)
            res = [nums[i], nums[l], nums[r]]
        
        if par_sum > 0:
            r -= 1
        else:
            l += 1
res.sort()
for i in res:
    print(i, end = " ")