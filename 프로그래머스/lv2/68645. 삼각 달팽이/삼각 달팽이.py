
def solution(n):
    arr = [[0 for _ in range(i + 1)] for i in range(n)]
    x = -1
    y = 0
    num = 1
    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0:
                x += 1
            elif i % 3 == 1:
                y += 1
            else:
                x -= 1
                y -= 1
            arr[x][y] = num
            num += 1
    answer = []
    for _li in arr:
        answer.extend(_li)
    return answer