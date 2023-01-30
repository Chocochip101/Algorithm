import sys
from itertools import combinations
input = sys.stdin.readline


N, M = map(int, input().split())

teams = [[True for _ in range(N + 1)] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    teams[a][b] = False
    teams[b][a] = False

ans = 0
for combs in combinations(range(1, N + 1), 3):
    if teams[combs[0]][combs[1]] and teams[combs[0]][combs[2]] and teams[combs[1]][combs[2]]:
        ans += 1
                
print(ans)