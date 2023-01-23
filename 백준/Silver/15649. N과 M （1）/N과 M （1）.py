from itertools import permutations

N, M = map(int, input().split())

for c in permutations(range(1, N + 1), M):
    for n in c:
        print(n, end=" ")
    print()
