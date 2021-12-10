import sys
from collections import deque
input = sys.stdin.readline

def L(num):
    front = num % 1000
    back = num // 1000
    return front * 10 + back

def R(num):
    front = num % 10
    back = num // 10
    return front * 1000 + back

def bfs(start, dest):
    queue = deque()
    queue.append((start, ""))
    visited[start] = True
    while(queue):
        now, order = queue.popleft()
        if now == dest:
            return order

        # D
        if not visited[(now * 2) % 10000]:
            visited[(now * 2) % 10000] = True
            queue.append(((now * 2) % 10000, order + "D"))

        # S
        if now == 0 and not visited[9999]:
            visited[9999] = True
            queue.append((9999, order + "S"))
        elif not visited[now - 1]:
            visited[now - 1] = True
            queue.append((now - 1, order + "S"))

        # L
        if not visited[L(now)]:
            visited[L(now)] = True
            queue.append((L(now), order + "L"))
        # R
        if not visited[R(now)]:
            visited[R(now)] = True
            queue.append((R(now), order + "R"))


testcase = int(input())

for _ in range(testcase):
    visited = [False] * 10001
    src, dest = map(int,input().split())
    print(bfs(src, dest))