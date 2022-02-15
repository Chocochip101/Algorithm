import sys
#input = sys.stdin.readline

S, E, Q = input().split()

li = dict()

while True:
    try:
        T, Name = input().split()
    except:
        break
    if(T > Q):
        break
    if Name not in li.keys():
        li[Name] = 0
    if T <= S:
        li[Name] = 1
    elif E <= T <= Q and li[Name] == 1:
        li[Name] = 2
    
ans = 0
for n in li.keys():
    if li[n] == 2:
        ans += 1
print(ans)
