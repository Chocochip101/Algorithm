def solution(data, col, row_begin, row_end):
    data.sort(key = lambda x : (x[col - 1], -x[0]))

    answer = 0
    for i in range(row_begin, row_end + 1):
        answer = answer ^ S(data[i - 1], i)
    return answer
def S(data, i):
    ret = 0
    for d in data:
        ret += d % i
    return ret