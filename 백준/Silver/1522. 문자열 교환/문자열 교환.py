from collections import deque
s = input().rstrip()

ans = float('inf')

a_cnt = s.count('a')

for i in range(len(s)):
    temp = s
    if a_cnt + i > len(s):
        temp += s[:a_cnt + i - len(s)]
    ans = min(ans, temp[i: i + a_cnt].count('b'))
print(ans)