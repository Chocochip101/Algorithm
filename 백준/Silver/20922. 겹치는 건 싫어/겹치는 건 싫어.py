import sys
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().split()))


left = 0
right = 0

cnt = [0 for _ in range(100_010)]

# left ~ right - 1만 포함
result = 1
while right < N:
    if cnt[arr[right]] != K:
        cnt[arr[right]] += 1
        right += 1
    else:
        cnt[arr[left]] -= 1
        left += 1
    result = max(result, right - left)
print(result)