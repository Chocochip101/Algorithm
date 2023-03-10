import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

T = input().rstrip()
S = input().rstrip()

idx = 0
cnt = 0
while idx < len(T):
    if T[idx: idx + len(S)] == S:
        idx += len(S)
        cnt += 1
    else:
        idx += 1
print(cnt)
    