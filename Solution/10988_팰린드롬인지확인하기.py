s = input()
flag = True
for i in range(len(s) // 2):
    if s[i] != s[len(s) - i - 1]:
        flag = False
if flag:
    print(1)
else:
    print(0)