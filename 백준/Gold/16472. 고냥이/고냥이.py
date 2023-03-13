from collections import defaultdict
import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()

alpha = defaultdict(int)

ans = 1

s = 0
e = 0

while s < len(S) and e < len(S):
    alpha[S[e]] += 1

    if len(alpha) > N:
        while s <= e and len(alpha) > N:
            alpha[S[s]] -= 1
            if alpha[S[s]] == 0:
                alpha.pop(S[s])
            s += 1
            
    if len(set(alpha)) <= N:
        ans = max(ans, e - s)
    e += 1
print(ans + 1)

