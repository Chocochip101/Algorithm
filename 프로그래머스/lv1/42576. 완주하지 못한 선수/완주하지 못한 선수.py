from collections import Counter
def solution(participant, completion):
    c_par = Counter(participant)
    for n in completion:
        c_par[n] -= 1
        if c_par[n] == 0:
            c_par.pop(n)
    for i in c_par:
        answer = i
        return answer