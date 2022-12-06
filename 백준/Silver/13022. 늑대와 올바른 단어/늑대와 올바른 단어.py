word_li = set()
for i in range(1, 14):
    wolf = 'w' * i + 'o' * i + 'l' * i + 'f' * i
    word_li.add(wolf)

S = input().rstrip()
flag = True
idx = 0

while idx < len(S):
    temp = False

    for tok in word_li:

        if idx + len(tok) <= len(S) and S[idx:idx + len(tok)] == tok:
            idx += len(tok)
            temp = True
            break

    if not temp:
        flag = False
        break

if flag:
    print(1)
else:
    print(0)
