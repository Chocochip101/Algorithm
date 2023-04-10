import sys
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    
    N, M = map(int, input().split())
    graph = [[float('inf') if i!= j else 0 for i in range(N + 1)] for j in range(N + 1)]
    
    for _ in range(M):
        a, b, c = map(int, input().split())
        graph[a][b] = c
        graph[b][a] = c
        
    K = int(input())
    friends = list(map(int, input().split()))

    for t in range(1, N + 1):
        for i in range(1, N + 1):
            for j in range(1, N + 1):
                if i != j:
                    graph[i][j] = min(graph[i][j], graph[i][t] +  graph[t][j])
    ans = -1
    min_dist = float('inf')
    for room_num in range(1, N + 1):
        temp_d = 0
        for i in range(K):
            temp_d += graph[room_num][friends[i]]
        if min_dist > temp_d:
            min_dist = temp_d
            ans = room_num
    print(ans)