from collections import deque
import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    priority = list(map(int, input().split()))

    q = deque()
    for i in range(N):
        q.append([priority[i], i])
    
    ans = 0
    while q:
        now_p, now_i = q.popleft()
        if len(q) > 0 and now_p < max(q)[0]:
            q.append([now_p, now_i])
        else:
            ans += 1
            if now_i == M:
                break
            
    print(ans)