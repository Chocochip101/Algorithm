from collections import deque
def solution(s):
    answer = True
    stk = deque()
    for c in s:
        if c == '(':
            stk.append(c)
        else:
            if len(stk) > 0 and c == ')':
                stk.pop()
            else:
                answer = False
                break
    if len(stk) == 0 and answer:
        return True
    return False