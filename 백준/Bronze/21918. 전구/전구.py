N, M = map(int, input().split())
pl = list(map(int, input().split()))
for _ in range(M):
    a, b, c = map(int, input().split())
    if a == 1:
        pl[b - 1] = c
    elif a == 2:
        for i in range(b - 1, c):
            if pl[i] == 1:
                pl[i] = 0
            else:
                pl[i] = 1
    elif a == 3:
        for i in range(b - 1, c):
            pl[i] = 0
    elif a == 4:
        for i in range(b - 1, c):
            pl[i] = 1
for i in range(len(pl)):
    print(pl[i], end= ' ')