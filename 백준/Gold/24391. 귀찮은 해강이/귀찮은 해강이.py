import sys
input = sys.stdin.readline
N, M = map(int, input().split())

parent = [i for i in range(N + 1)]

def find(u):
    if u == parent[u]:
        return u
    parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    u = find(u)
    v = find(v)
    
    if u == v:
        return
    parent[u] = v
    
for _ in range(M):
    a, b = map(int, input().split())
    union(a, b)
    
schedule = list(map(int, input().split()))
prev = -1
ans = 0
for sc in schedule:
    if prev == -1:
        prev = find(sc)
    else:
        if prev != find(sc):
            prev = find(sc)
            ans += 1
print(ans)