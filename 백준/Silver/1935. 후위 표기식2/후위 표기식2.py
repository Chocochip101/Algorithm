from collections import defaultdict, deque

N = int(input())
symbols = input().rstrip()
alphabets = defaultdict(int)
stk = deque()

for i in range(N):
    alphabets[chr(65 + i)] = int(input())

for symbol in symbols:
    if ord("A") <= ord(symbol) <= ord("Z"):
        stk.append(alphabets[symbol])
    elif symbol == "+":
        num1 = stk.pop()
        num2 = stk.pop()
        stk.append(num2 + num1)
    elif symbol == "-":
        num1 = stk.pop()
        num2 = stk.pop()
        stk.append(num2 - num1)
    elif symbol == "*":
        num1 = stk.pop()
        num2 = stk.pop()
        stk.append(num2 * num1)
    elif symbol == "/":
        num1 = stk.pop()
        num2 = stk.pop()
        stk.append(num2 / num1)
print("{:.2f}".format(stk.pop()))