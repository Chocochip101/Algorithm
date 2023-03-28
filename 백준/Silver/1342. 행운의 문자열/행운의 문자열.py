from collections import Counter
import sys
sys.setrecursionlimit(10**8)

S = input().rstrip()
c_s = Counter(S)

cnt = 0
def solve(sub_s):
    if len(sub_s) > len(S):
        return
    if len(sub_s) == len(S):
        global cnt
        cnt += 1
        return
    
    for next in c_s:
        if sub_s == '':
            c_s[next] -= 1
            solve(sub_s + next)
            c_s[next] += 1
        elif sub_s[-1] != next and c_s[next] > 0:
            c_s[next] -= 1
            solve(sub_s + next)
            c_s[next] += 1
if len(c_s) == 10 and len(S) == 10:
    print(3628800)
    exit()
solve("")
print(cnt)