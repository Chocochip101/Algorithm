import sys
import math
input = sys.stdin.readline


N = int(input())
isPrime = [True for _ in range(N + 1)]
prime_list = []

def prime():
    for i in range(2, int(math.sqrt(N)) + 1):
        if isPrime[i]:
            for j in range(i * 2, N + 1, i):
                isPrime[j] = False
prime()
for i in range(2, N + 1):
    if isPrime[i]:
        prime_list.append(i)
        
ans = 0
l = 0
r = 1

M = len(prime_list)

while r <= M:
    par_sum = sum(prime_list[l:r])
    if par_sum == N:
        ans += 1
        r += 1
    elif par_sum < N:
        r += 1
    else:
        l += 1 
print(ans)