import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

ans = 0
while len(A) > 1:
    A.sort()
    temp_f = A[0]
    temp_s = A[1]
    
    ans += temp_f * temp_s
    A.remove(temp_f)
    A.remove(temp_s)
    
    A.append(temp_f + temp_s)
    
print(ans)