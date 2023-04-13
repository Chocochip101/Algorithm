from collections import defaultdict
tickets_dict = defaultdict(list)
ans = []

def dfs(now:str, _li, N):
    if len(_li) == N:
        global ans
        ans.append(_li)
        return
    for i in range(len(tickets_dict[now])):
        next, visited = tickets_dict[now][i][0], tickets_dict[now][i][1]
        if not visited:
            tickets_dict[now][i][1] = True
            dfs(next, _li + [next], N)
            tickets_dict[now][i][1] = False


def solution(tickets):

    for tik in tickets:
        tickets_dict[tik[0]].append([tik[1], False])
        tickets_dict[tik[0]].sort()
    global ans

    dfs('ICN', ['ICN'], len(tickets) + 1)

    ans.sort(key=lambda x: "".join(x))

    return ans[0]

