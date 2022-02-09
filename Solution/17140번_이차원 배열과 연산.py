import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline
from collections import Counter

def rc(s):
    max_len = 0
    len_s = len(s)
    for j in range(len_s):
        a = [i for i in s[j] if i != 0]
        a = Counter(a).most_common()
        a.sort(key = lambda x : (x[1], x[0]))
        s[j] = []
        for fi, se in a:
            s[j].append(fi)
            s[j].append(se)
        len_a = len(a)
        if max_len < len_a * 2: max_len = len_a * 2
    # 0 채우기
    for j in range(len_s):
        for k in range(max_len - len(s[j])):
            s[j].append(0)
        s[j] = s[j][:100]
    return s


r, c, k = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(3)]

cnt = 0
while cnt <= 100:
    try:
        if A[r - 1][c - 1] == k:
            break
    except:
        pass

    if len(A) >= len(A[0]):
        A = rc(A)
    else:
        # 행렬 뒤집기
        A = list(zip(*A))
        A = rc(A)
        A = list(zip(*A))
    cnt += 1


if cnt > 100:
    print(-1)
else:
    print(cnt)