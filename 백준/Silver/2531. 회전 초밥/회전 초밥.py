from collections import deque
import sys
input = sys.stdin.readline

N, d, k, c = map(int, input().split())

q = deque()
temp_q = deque()

for _ in range(N):
    q.append(int(input()))

for i in range(k):
    temp = q.popleft()
    temp_q.append(temp)
    q.append(temp)

_s = set(temp_q)
_s.add(c)

ans = len(_s)
  
while q:
    temp = q.popleft()
    temp_q.popleft()
    temp_q.append(temp)
    
    _s = set(temp_q)
    _s.add(c)
    
    ans = max(ans, len(_s))
    
print(ans)
