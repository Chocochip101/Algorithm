from collections import deque

def solution(priorities, location):
    q = deque()
    for i in range(len(priorities)):
        q.append([priorities[i], i])
    answer = 0

    while q:
        now_p, now_idx = q.popleft()
        if len(q) > 0 and now_p < max(q)[0]:
            q.append([now_p, now_idx])
        else:
            answer += 1
            if now_idx == location:
                return answer
