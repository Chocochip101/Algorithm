N = input()

total = 0
flag = False

li = []
for c in N:
    if int(c) == 0:
        flag = True
    li.append(c)
    total += int(c)
    
    
li.sort(reverse=True)
if flag and total % 3 == 0:
    print(''.join(li))
else:
    print(-1)