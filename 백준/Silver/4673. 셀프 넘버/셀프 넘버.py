d_list=[]

def d(num):
    str_num = str(num)
    sum = 0
    for i in range(len(str_num)):
        sum += int(str_num[i])
    return sum + num

for i in range(10000):
    d_list.append(d(i))

for i in range(10000):
    if i not in d_list:
        print(i)