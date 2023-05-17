import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

arr.sort()

ans = 1
for i in range(N):
    for j in range(i + 1, N):
        if arr[i] + arr[i + 1] > arr[j]:
            ans = max(ans, j - i + 1)
    
print(ans)