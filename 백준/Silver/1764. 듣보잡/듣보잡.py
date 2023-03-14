import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

N, M = map(int, input().split())
s1 = set()
for _ in range(N):
    s1.add(input().rstrip())

s2 = set()
for _ in range(M):
    s2.add(input().rstrip())

result = sorted(s1.intersection(s2))
print(len(result))
for n in result:
    print(n)