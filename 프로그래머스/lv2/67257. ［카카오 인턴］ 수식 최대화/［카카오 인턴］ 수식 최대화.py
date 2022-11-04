import sys
from itertools import permutations
from collections import deque
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
INF = 10**9

def doOp(num1, num2, op):
    num1 = int(num1)
    num2 = int(num2)
    if op == '+':
        return num1 + num2
    elif op == '-':
        return num1 - num2
    else:
        return num1 * num2

def calculateExpression(expression, oper):
    temp = ''
    array = []
    for c in expression:
        if c == '*' or c == '+' or c == '-':
            array.append(temp)
            array.append(c)
            temp = ''
        else:
            temp += c
    array.append(temp)

    for op in oper:
        stk = []
        while len(array) != 0:
            temp = array.pop(0)
            if temp == op:
                stk.append(doOp(stk.pop(), array.pop(0), op))
            else:
                stk.append(temp)
        array = stk
    return abs(array[0])

def solution(expression):
    answer = -1
    op = ['+', '-', '*']
    op = list(permutations(op, 3))
    for i in op:
        answer = max(answer, calculateExpression(expression, i))
    return answer
