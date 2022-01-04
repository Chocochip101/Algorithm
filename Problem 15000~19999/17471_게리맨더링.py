import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline

def bfs(li):
    total = arr[li[0] - 1]
    visited = set()
    q = deque([li[0]])
    visited.add(li[0])
    while q:
        now = q.popleft()
        for next in board[now]:
            if next not in visited and next in li:
                q.append(next)
                visited.add(next)
                total += arr[next - 1]
    return total, len(visited)


N = int(input())
# 0 ~ N - 1
arr = list(map(int, input().split()))
# 1 ~ N
board = [[] for _ in range(N + 1)]
res = float('inf')
for i in range(1, N + 1):
    temp = list(map(int, input().split()))
    for j in range(temp[0]):
        board[i].append(temp[j + 1])

for i in range(1, N // 2 + 1):
    for comb in combinations(range(1, N + 1), i):
        t1, l1 = bfs(comb)
        t2, l2 = bfs([k for k in range(1, N + 1)  if k not in comb])
        if l1 + l2 == N:
            res = min(res, abs(t1 - t2))
if res == float('inf'):
    print(-1)
else:
    print(res)
