import sys
sys.setrecursionlimit(10**8)


def solution(arr):
    answer = [0, 0]
    def solve(s, e, N):
        flag = arr[s][e]
        for i in range(s, s + N):
            for j in range(e, e + N):
                if flag != arr[i][j]:
                    N //= 2
                    solve(s, e, N)
                    solve(s, e + N, N)
                    solve(s + N, e, N)
                    solve(s + N, e + N, N)
                    return
        answer[flag] += 1
    solve(0, 0, len(arr))       
    return answer