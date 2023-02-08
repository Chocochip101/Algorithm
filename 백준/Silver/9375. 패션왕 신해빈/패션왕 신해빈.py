from collections import defaultdict
T = int(input())

for _ in range(T):
    N = int(input())
    d = defaultdict(list)
    for _ in range(N):
        a, b = input().split()
        d[b].append(a)
    if len(d.keys()) == 1:
        ans = 0
        for k in d.keys():
            ans += (len(d[k]))
        print(ans)
    else:
        ans = 1
        for k in d.keys():
            ans *= (len(d[k]) + 1)
        print(ans - 1)