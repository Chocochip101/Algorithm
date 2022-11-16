T=int(input())

Fibonacci = [-1] * 41
'''
Input:  매개변수 N= 구할 피보나치 수
Output: 그에 해당하는 피보나치 수
Description: 피보나치를 구하는 함수
'''
cnt_fibo = [[0,0] for _ in range(41)]

# 얕은 복사, 깊은 복사
# cnt_fibo = [[0, 0]] * 41



cnt_fibo[0] = [1,0]
cnt_fibo[1] = [0,1]

for i in range(2, 41):
    cnt_fibo[i][0] = cnt_fibo[i-1][0] + cnt_fibo[i-2][0]
    cnt_fibo[i][1] = cnt_fibo[i-1][1] + cnt_fibo[i-2][1]
    
for _ in range(T):
    N=int(input())

        
    print(cnt_fibo[N][0],end=' ')
    print(cnt_fibo[N][1])
        
        

'''
Case 1)
T = 10번
N = 40 -> 39
10 * 39 = 390

Case 2)
39번
39 + 10 = 49
'''
