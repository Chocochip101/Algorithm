from collections import defaultdict

def solution(topping):
    brother = defaultdict(int)
    brother[topping[0]] += 1
    
    chulsu = defaultdict(int)
    for i in range(1, len(topping)):
        chulsu[topping[i]] += 1

    
    answer = 0
    for i in range(1, len(topping)):
        if isSame(brother, chulsu):
            answer += 1
        brother[topping[i]] += 1
        chulsu[topping[i]] -= 1
        if chulsu[topping[i]] <= 0:
            chulsu.pop(topping[i])
        
    return answer
def isSame(brother, chulsu):
    if len(brother.keys()) == len(chulsu.keys()):
        return True
    return False