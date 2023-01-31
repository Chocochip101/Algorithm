V, E = map(int, input().split())
parent = [i for i in range(V + 1)]
edges = []
for _ in range(E):
    a, b, c = map(int, input().split())
    edges.append([c, a, b])

def find(u):
    if parent[u] != u:
        parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    u = find(u)
    v = find(v)
    if u < v:
        parent[v] = u
    else:
        parent[u] = v

res = 0

edges.sort()
for c, a, b in edges:
    if find(a) != find(b):
        union(a, b)
        res += c

print(res)