import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
N = int(input())

strength = []
weight = []
for _ in range(N):
    s, w = map(int, input().split())
    strength.append(s)
    weight.append(w)

def calBroke():
    cnt = 0
    for i in range(N):
        if strength[i] <= 0:
            cnt += 1
    return cnt

res = 0
def solve(now):
    global res
    
    res = max(res, calBroke())

    if now == N or res == N:
        return
    
    if strength[now] <= 0:
        solve(now + 1)
    # 계란치기
    for next in range(N):
        if next != now and strength[next] > 0 and strength[now] > 0:
            # 손에 든 계란이 깨졌을 경우
            strength[now] -= weight[next]
            strength[next] -= weight[now]
            solve(now + 1)
            strength[now] += weight[next]
            strength[next] += weight[now]
            
solve(0)
print(res)