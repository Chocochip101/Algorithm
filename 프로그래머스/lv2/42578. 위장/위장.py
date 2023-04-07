from collections import defaultdict
def solution(clothes):
    d_c = defaultdict(list)
    for clothe in clothes:
        d_c[clothe[1]].append(clothe[0])

    if len(d_c) == 1:
         for i in d_c:
            return len(d_c[i])
    answer = 1
    for i in d_c:
        answer *= (len(d_c[i]) + 1)
        
    return answer - 1