import sys
input = sys.stdin.readline

def dist(a, b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2

def dfs(cur):
    for j in range(N):
        if dist(location[cur], location[j])>(location[cur][2]+location[j][2])**2 or cur==j or visited[j]:
            continue
        visited[j]=True
        dfs(j)
        
T = int(input())

for _ in range(T):
    N = int(input())
    ans = 0
    location=[]
    
    visited=[False for _ in range(N)]
    for _ in range(N ):
        location.append(list(map(int, input().split())))
    for i in range(N):
        if not visited[i]:
            dfs(i)
            ans += 1
    print(ans)