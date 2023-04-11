from collections import deque
import sys
input = sys.stdin.readline

while True:
    s = input().rstrip()
    if len(s) == 1 and s[0] == '.':
        break
    
    q = deque()
    
    flag = True
    for c in s:
        if c == '(' or c == '[':
            q.append(c)
            
        elif c == ')':
            if len(q) == 0:
                flag = False
                break 
            
            now = q.pop()
            if now != '(':
                flag = False
                break
        elif c == ']':
            if len(q) == 0:
                flag = False
                break
            now = q.pop()
            if now != '[':
                flag = False
                break
    if flag and len(q) == 0:
        print('yes')
    else:
        print('no')