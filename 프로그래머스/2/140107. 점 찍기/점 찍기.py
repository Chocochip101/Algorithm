import math
def solution(k, d):
    
    answer = 0
    # (0, 0) ~ (0, d) 
    # (1, 0) ~ (1, )
    # (...)
    # (d, 0)
    
    for i in range(0, d + 1, k):
        answer += y(i, k, d)
    return answer

def y(x, k, d):
    expectedY = math.sqrt(d * d - x * x)
    return expectedY // k + 1