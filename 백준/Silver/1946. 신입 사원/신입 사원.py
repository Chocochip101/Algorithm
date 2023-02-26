import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    scores = list()
    for _ in range(N):
        scores.append(list(map(int, input().split())))

    scores.sort()
    
    min_num = scores[0][1]
    cnt = 0
    for i in range(1, N):
        if scores[i][1] > min_num:
            cnt += 1
        elif(scores[i][1] < min_num):
            min_num = scores[i][1]
            
    print(N - cnt)