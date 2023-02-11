def is_correct(s):
    stk = []
    
    for i in range(len(s)):
        if len(stk) == 0:
            stk.append(s[i])
            continue
        
        if stk[-1] == '[' and s[i] == ']':
            stk.pop()
        elif stk[-1] == '(' and s[i] == ')':
            stk.pop()
        elif stk[-1] == '{' and s[i] == '}':
            stk.pop()
        else:
            stk.append(s[i])
    
    if len(stk) == 0:
        return True
    else:
        return False

def solution(s):
    answer = 0
    cnt = 0
    while cnt < len(s):
        if is_correct(s):
            answer += 1
        s = s[1:] + s[0]
        cnt += 1
    return answer
