from collections import deque
def solution(order):
    orders = deque(order)
    sequence = deque(range(1, len(order) + 1))
    subContainer = []
    
    answer = 0
    
    while sequence and orders:
        if subContainer:
            if subContainer[-1] == orders[0]:
                subContainer.pop()
                orders.popleft()
                answer += 1
                continue
        if sequence[0] == orders[0]:
            answer += 1
            sequence.popleft()
            orders.popleft()  
        elif sequence[0] != orders[0]:
            subContainer.append(sequence[0])
            sequence.popleft()

    while subContainer and orders:
        if subContainer[-1] == orders[0]:
            subContainer.pop()
            orders.popleft()
            answer += 1
            continue
        break
    return answer