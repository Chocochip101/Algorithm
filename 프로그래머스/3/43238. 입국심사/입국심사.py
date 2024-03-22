import heapq
def solution(n, times):
    left = 0
    right = max(times) * n + 1
    answer = max(times) * n + 1
    
    while left < right:
        mid = (left + right) // 2
        if canDo(n, times, mid):
            answer = min(answer, mid)
            right = mid
        else:
            left = mid + 1
    return answer

def canDo(n, times, mid):
    result = 0
    for time in times:
        result += mid // time
    if result >= n:
        return True
    return False
    