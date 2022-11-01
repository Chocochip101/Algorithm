import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

INF = 987654321
dp = [[-1] * 200 for _ in range(200)]
problems = []
max_alp = -1
max_cop = -1

def solve(alp, cop):
    if alp >= max_alp and cop >= max_cop:
        return 0

    if dp[alp][cop] != -1:
        return dp[alp][cop]

    dp[alp][cop] = INF

    dp[alp][cop] = min(solve(min(max_alp, alp + 1), cop) + 1, solve(alp, min(max_cop, cop + 1)) + 1)
    for i in range(len(problems)):
        if alp >= problems[i][0] and cop >= problems[i][1]:
            dp[alp][cop] = min(dp[alp][cop], solve(min(max_alp, alp + problems[i][2]), min(max_cop, cop + problems[i][3])) + problems[i][4])
    return dp[alp][cop]

def solution(alp, cop, problem):
    global max_alp, max_cop
    global problems
    problems = problem
    global  dp

    for i in range(len(problems)):
        max_alp = max(max_alp, problems[i][0])
        max_cop = max(max_cop, problems[i][1])

    return solve(alp, cop)
