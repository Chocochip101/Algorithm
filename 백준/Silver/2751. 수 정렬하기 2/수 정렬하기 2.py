import sys
input = sys.stdin.readline
N = int(input())

_li = []
for _ in range(N):
    a = int(input())
    _li.append(a)
    

for num in sorted(_li):
    print(num)