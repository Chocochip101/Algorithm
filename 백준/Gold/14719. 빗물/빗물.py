import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

H, W = map(int, input().split())
height = list(map(int, input().split()))
ans = 0

for i in range(1, W - 1):
    l = max(height[:i])
    h = max(height[i + 1:])
    
    min_val = min(l, h)
    
    if height[i] < min_val:
        ans += min_val - height[i]

print(ans)