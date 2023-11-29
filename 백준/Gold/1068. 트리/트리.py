N = int(input())
graph = [[] for _ in range(51)]

numbers = list(map(int, input().split()))
root = -1
for i in range(N):
    if numbers[i] == -1:
        root = i
    else:
        graph[numbers[i]].append(i)
        
    
def deleteNode(now, n):
    if n in graph[now]:
        graph[now].remove(n)
        return
    else:
        for next in graph[now]:
            deleteNode(next, n)
    
    
M = int(input())
deleteNode(root, M)

cnt = 0
def countLeafNode(now):
    global cnt
    if len(graph[now]) == 0:
        cnt += 1
        return
    else:
        for next in graph[now]:
            countLeafNode(next)
            
countLeafNode(root)

if root == M:
    print(0)
else:
    print(cnt)