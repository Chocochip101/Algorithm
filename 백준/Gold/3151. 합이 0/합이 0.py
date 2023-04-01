import sys
import bisect
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
nums.sort()

ans = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        tar = - (nums[i] + nums[j])
        ans += (bisect.bisect_right(nums, tar, i + 1, j) - bisect.bisect_left(nums, tar, i + 1, j))

print(ans)