import sys
input = sys.stdin.readline

N, X = map(int, input().split())
visitor_cnt = list(map(int, input().split()))

s = 0
e = 0

par_sum = visitor_cnt[0]

cnt_ans = 0
max_ans = 0
while s < N:
    if e - s < X - 1:
        if e == N - 1:
            break
        else:
            e += 1
            par_sum += visitor_cnt[e]
    elif e - s == X - 1:
        if max_ans == par_sum and max_ans != 0:
            cnt_ans += 1
        elif max_ans < par_sum:
            cnt_ans = 1
            max_ans = par_sum

        if e == N - 1:
            par_sum -= visitor_cnt[s]
            s += 1
        else:
            e += 1
            par_sum += visitor_cnt[e]
    else:  
        par_sum -= visitor_cnt[s]
        s += 1
    
if max_ans != 0:
    print(max_ans)
    print(cnt_ans)
else:
    print('SAD')
