from collections import deque, defaultdict

def diffAlpha(s1, s2):
    cnt = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            cnt += 1
    return cnt

def solution(begin, target, words):
    dist = defaultdict()
    for w in words:
        dist[w] = -1
        
    q = deque()
    dist[begin] = 0
    q.append(begin)
    while q:
        now = q.popleft()
        if now == target:
            return dist[now]
        for next in words:
            if diffAlpha(next, now) == 1 and dist[next] == -1:
                dist[next] = dist[now] + 1
                q.append(next)
    return 0