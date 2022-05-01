now = []
for i in range(3):
    now.append(int(input()))
    
pred = []
for i in range(3):
    pred.append(int(input()))

ck = [False] * 3
stk = 0
for i in range(3):
    if now[i] == pred[i]:
        stk += 1
        ck[i] = True
ball = 0
for i in range(3):
    if (not ck[i]) and (now[i] in pred):
        ball += 1
ans = ""
if stk > 0:
    ans += str(stk)
    ans += "S"
if ball > 0:
    ans += str(ball)
    ans += "B"
print(ans)