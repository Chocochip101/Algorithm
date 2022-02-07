n = int(input())

def solve(a):
    ans = 0
    temp = str(a)
    for p in temp:
        if p == '3' or p == '6' or p == '9':
            ans += 1
    return ans
res = 0
for i in range(1, n + 1):
    res += solve(i)
print(res)