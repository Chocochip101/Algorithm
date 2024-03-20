def solution(k, ranges):
    y = getY(k)
    areas = getPartialSumAreas(y)

    answer = []
    for r in ranges:
        answer.append(getArea(areas, r))
    return answer


def solution(k, ranges):
    answer = []
    arr = getY(k)
    for r in ranges:
        total = 0
        tmp_arr = arr[r[0]:len(arr)+r[1]]
        if r[0] >= r[1]+len(arr):
            answer.append(-1)
            continue
        for i in range(len(tmp_arr)-1):
            total += ((tmp_arr[i] + tmp_arr[i+1])/2)
        answer.append(total)
    return answer

def getY(k):
    res = []
    while k != 1:
        res.append(k)
        if k % 2 == 0:
            k = k // 2
        else:
            k = k * 3 + 1
    res.append(1)
    return res


