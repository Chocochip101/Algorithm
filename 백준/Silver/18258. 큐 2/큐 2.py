from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
q = deque()

for _ in range(N):
    S = list(input().split())
    if S[0] == 'push':
        q.append(S[1])
    elif S[0] == 'pop':
        if q:
            print(q.popleft())
        else:
            print(-1)
    elif S[0] == 'size':
        print(len(q))
    elif S[0] == 'empty':
        if q:
            print(0)
        else:
            print(1)
    elif S[0] == 'front':
        if q:
            print(q[0])
        else:
            print(-1)
    elif S[0] == 'back':
        if q:
            print(q[-1])
        else:
            print(-1)
