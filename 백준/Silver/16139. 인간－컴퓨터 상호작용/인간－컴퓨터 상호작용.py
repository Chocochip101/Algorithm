import sys
input = sys.stdin.readline

S = input().rstrip()

parSum = [[0 for _ in range(len(S) + 1)] for _ in range(26)]
for i in range(0, 26):
    k = chr(i + ord('a'))
    for j in range(len(S)):
        if(S[j] == k):
            parSum[i][j + 1] = parSum[i][j] + 1
        else:
            parSum[i][j + 1] = parSum[i][j]


q = int(input())

for _ in range(q):
    a, l, r = input().split()
    l = int(l)
    r = int(r)
    k = ord(a) - ord('a')
    print(parSum[k][r + 1] - parSum[k][l])
    