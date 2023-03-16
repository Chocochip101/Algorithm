def solve(times, t):
    res = 0
    for i in range(len(times)):
        res += (t // times[i])
    return res

def solution(n, times):
    l = 0
    h = n * max(times)
    
    answer = float('inf')
    while l <= h:
        mid = (l + h) // 2
        person_count = solve(times, mid)
        if person_count < n:
            l = mid + 1
        else:
            answer = min(answer, mid)
            h = mid - 1

    return answer