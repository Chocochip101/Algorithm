import sys

N, K = map(int, sys.stdin.readline().split())
coin_list = []

for i in range(N):
    temp = int(sys.stdin.readline())
    coin_list.append(temp)

count = 0
for i in range(N-1, -1, -1):
    count += K // coin_list[i]
    K = K % coin_list[i]
    if K < coin_list[i]:
        continue
print(count)