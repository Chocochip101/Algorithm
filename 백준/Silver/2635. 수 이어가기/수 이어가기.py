import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

N = int(input())


def count(n, i):
    cnt = 0
    li = []
    while n >= 0:
        li.append(n)
        temp_n = n
        n = i
        i = temp_n - i
        cnt += 1
    return [cnt, li]

def solve(n):
    res = -1
    res_li = []
    for i in range(1, n + 1):
        if res < count(n, i)[0]:
            res = count(n, i)[0]
            res_li = count(n, i)[1]
    return [res, res_li]

res, res_li = solve(N)
print(res)
for i in res_li:
    print(i, end=' ')