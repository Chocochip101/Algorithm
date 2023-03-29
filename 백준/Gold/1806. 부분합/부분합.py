import sys

N, S = map(int, input().split())
nums = list(map(int, input().split()))

s = 0
e = 0

par_sum = 0
res = N + 1
while s < N:

    while par_sum < S and e < N:
        par_sum += nums[e]
        e += 1
        
    if par_sum >= S:
        res = min(e - s, res)
        par_sum -= nums[s]
        s += 1

    else:
        if e < N:
            par_sum += nums[e]
            e += 1
        else:
            par_sum -= nums[s]
            s += 1

if res == N + 1:
    print(0)
else:
    print(res)