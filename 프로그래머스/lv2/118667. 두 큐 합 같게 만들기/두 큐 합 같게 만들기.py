from collections import deque

def solution(queue1, queue2):
    
    max_size = len(queue1)
    
    total1 = sum(queue1)
    total2 = sum(queue2)
       
    queue1 = deque(queue1)
    queue2 = deque(queue2)
 
    answer = 0
    while answer <= max_size * 3:
        if total1 == total2:
            break
        elif total1 > total2:
            target = queue1.popleft()
            queue2.append(target)
            
            total1 -= target
            total2 += target
            
            answer += 1
        elif total1 < total2:
            target = queue2.popleft()
            queue1.append(target)
            
            total2 -= target
            total1 += target
            
            answer += 1
        
    if answer >= max_size * 3:
        answer = -1
        
        
    return answer