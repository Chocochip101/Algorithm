import sys
input = sys.stdin.readline
N = int(input())
nums = list(map(int, input().split()))

dp0 = [0 for _ in range(N)]
dp1 = [0 for _ in range(N)]

for i in range(1, N):
    if nums[i - 1] <= nums[i]:
        dp0[i] = dp0[i - 1] + 1
    
    if nums[i - 1] >= nums[i]:
        dp1[i] = dp1[i - 1] + 1

print(max(max(dp0), max(dp1)) + 1)  