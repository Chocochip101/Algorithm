import math

def solve(n):
    if int(math.sqrt(n)) ** 2 == n:
        return True
    else:
        return False
    
def solution(left, right):
    answer = 0
    for i in range(left, right + 1):
        if solve(i):
            answer -= i
        else:
            answer += i
    return answer