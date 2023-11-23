from collections import defaultdict

N, M, k = map(int, input().split())
A = list(map(int, input().split()))
    
parent = [i for i in range(N + 1)]

def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    if u == v:
        return
    u = find(u)
    v = find(v)
    parent[u] = v
    

for _ in range(M):
    v, w = map(int, input().split())
    union(v, w)

friends_dict = defaultdict(int)


for i in range(1, N + 1):
    if find(i) not in friends_dict.keys():
        friends_dict[find(i)] = 987654321
    friends_dict[find(i)] = min(A[i - 1], friends_dict[find(i)])
    
total = 0
for kk in friends_dict.keys():
    total += friends_dict[kk]
    
if total > k:
    print("Oh no")
else:
    print(total)