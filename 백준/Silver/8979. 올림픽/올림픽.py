N, K = map(int, input().split())
medals = []
for _ in range(N):
    a, g, s, b = map(int, input().split())
    medals.append([g, s, b, a])
    
medals.sort(key=lambda x: (-x[0], -x[1], -x[2]))

ranks = [1 for _ in range(N)]
stk = 1
for i in range(1, N):
    if medals[i - 1][0] == medals[i][0] and medals[i - 1][1] == medals[i][1] and medals[i - 1][2] == medals[i][2]:
        ranks[i] = ranks[i - 1]
        stk += 1
    else:
        ranks[i] = ranks[i - 1] + stk 
        stk = 1

for i in range(N):
    if medals[i][3] == K:
        print(ranks[i])
        break