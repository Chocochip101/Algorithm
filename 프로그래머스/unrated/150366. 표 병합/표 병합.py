import sys
sys.setrecursionlimit(10**8)

MAX = 51
parent = [[[i, j] for j in range(MAX)] for i in range(MAX)]
graph = [['EMPTY' for _ in range(MAX)] for _ in range(MAX)]

def find(x, y):
    if parent[x][y] == [x, y]:
        return parent[x][y]
    parent[x][y] = find(parent[x][y][0], parent[x][y][1])
    return parent[x][y]


def union(a, b, c, d):

    a, b = find(a, b)
    c, d = find(c, d)

    if a == c and b == d:
        return

    if graph[a][b] == 'EMPTY':
        parent[a][b] = [c, d]
    else:
        parent[c][d] = [a, b]

def solution(commands):
    answer = []
    for command in commands:
        li_command = command.split()
        if li_command[0] == 'UPDATE' and len(li_command) == 4:
            px, py = find(int(li_command[1]), int(li_command[2]))
            graph[px][py] = li_command[3]

        elif li_command[0] == 'UPDATE':
            for i in range(MAX):
                for j in range(MAX):
                    px, py = find(i, j)
                    if graph[px][py] == li_command[1]:
                        graph[px][py] = li_command[2]

        elif li_command[0] == 'MERGE':
            union(int(li_command[1]), int(li_command[2]), int(li_command[3]), int(li_command[4]))

        elif li_command[0] == 'UNMERGE':
            px, py = find(int(li_command[1]), int(li_command[2]))
            prev_s = graph[px][py]
            temp_li = []
            for i in range(MAX):
                for j in range(MAX):
                    if i == int(li_command[1]) and j == int(li_command[2]):
                        continue
                    if [px, py] == find(i, j):
                        temp_li.append([i, j])
            for x, y in temp_li:
                parent[x][y] = [x, y]
                graph[x][y] = 'EMPTY'

            parent[int(li_command[1])][int(li_command[2])] = [int(li_command[1]), int(li_command[2])]
            graph[int(li_command[1])][int(li_command[2])] = prev_s

        elif li_command[0] == 'PRINT':
            px, py = find(int(li_command[1]), int(li_command[2]))
            answer.append(graph[px][py])

    return answer
