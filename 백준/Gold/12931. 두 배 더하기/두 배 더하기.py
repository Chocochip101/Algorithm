N = int(input())
B = list(map(int, input().split()))


ans = 0

while True:
    zeros = 0
    for i in range(N):
        if B[i] == 0:
            zeros += 1
        if B[i] % 2 == 1:
            B[i] -= 1
            ans += 1
    if zeros == N:
        break
    
    isEven = False
    for i in range(N):
        if B[i] % 2 == 0 and B[i] > 0:
            B[i] //= 2
            isEven = True
       
        
    if isEven:
        ans += 1
        
    
print(ans)