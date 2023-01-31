import sys
sys.setrecursionlimit(10**8)

N = int(input())
_li = list(map(int, input().split()))

res = -1

def solve(li, energy):
    if len(li) == 2:
        global res
        res = max(res, energy)
        return

    for i in range(1, len(li) - 1):
        solve(li[:i] + li[i + 1:], energy + li[i - 1] * li[i + 1])

solve(_li, 0)

print(res)