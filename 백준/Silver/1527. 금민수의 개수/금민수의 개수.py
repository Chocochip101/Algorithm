import sys

a, b = map(int, input().split())
res = set()
def solve(now):
    if now > b:
        return
    if a <= now <= b:
        res.add(now)
    solve(int('4' + str(now)))
    solve(int('7' + str(now)))
    
solve(4)
solve(7)
print(len(res))