from collections import deque
def solution(queue1, queue2):
    sumQ1 = sum(queue1)
    sumQ2 = sum(queue2)
    maxLength = len(queue1)
    answer = 0
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    
    while answer < maxLength * 3:

        if sumQ1 == sumQ2:
            return answer
        elif sumQ1 < sumQ2:
            temp = queue2.popleft()
            queue1.append(temp)
            sumQ1 += temp
            sumQ2 -= temp
        else:
            temp = queue1.popleft()
            queue2.append(temp)
            sumQ2 += temp
            sumQ1 -= temp
        answer += 1
    return -1