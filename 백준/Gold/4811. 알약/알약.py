cache = [[-1 for _ in range(32)] for _ in range(32)]

def solve(w, h):
    if w == 1:
        return 1
    if cache[w][h] != -1:
        return cache[w][h]
    ret = 0
    if w > 0:
        ret += solve(w - 1, h + 1)
    if h > 0:
        ret += solve(w, h - 1)
    cache[w][h] = ret
    return ret

while True:
    N = int(input())
    if N == 0:
        break
    print(solve(N + 1, 0))