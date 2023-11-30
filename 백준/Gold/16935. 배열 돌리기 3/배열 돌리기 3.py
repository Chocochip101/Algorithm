import sys
input = sys.stdin.readline



N, M, R = map(int, input().split())
A = []
for _ in range(N):
    A.append(list(map(int, input().split())))
operations = list(map(int, input().split()))

def Operation1():
    global A, N, M
    newList = []
    for i in range(N - 1, -1, -1):
        newList.append(A[i])
    A = newList
    return

def Operation2():
    global A, N, M
    for row in A:
        row.reverse()
    return

def Operation3():
    global A, N, M
    temp = zip(*A)
    A = []
    for row in temp:
        A.append(list(reversed(row)))
    N, M = M, N
    return

def Operation4():
    global A, N, M
    temp = zip(*A)
    A = []
    for row in temp:
        A.append(list(row))
    A.reverse()
    N, M = M, N
    return

def Operation5():
    global A, N, M
    first = []
    second = []
    third = []
    fourth = []
    for i in range(N // 2):
        first.append(A[i][:M // 2])
        
    for i in range(N // 2):
        second.append(A[i][M // 2:])
        
    for i in range(N // 2, N):
        fourth.append(A[i][:M // 2])
        
    for i in range(N // 2, N):
        third.append(A[i][M // 2 : ])

    A = []
    for i in range(N // 2):
        A.append(fourth[i] + first[i])
    for i in range(N // 2):
        A.append(third[i] + second[i])
    return

def Operation6():
    global A, N, M
    first = []
    second = []
    third = []
    fourth = []
    for i in range(N // 2):
        first.append(A[i][:M // 2])
        
    for i in range(N // 2):
        second.append(A[i][M // 2:])
        
    for i in range(N // 2, N):
        fourth.append(A[i][:M // 2])
        
    for i in range(N // 2, N):
        third.append(A[i][M // 2 : ])

    A = []
    for i in range(N // 2):
        A.append(second[i] + third[i])
    for i in range(N // 2):
        A.append(first[i] + fourth[i])
    return

for operation in operations:
    if operation == 1:
        Operation1()
    elif operation == 2:
        Operation2()
    elif operation == 3:
        Operation3()
    elif operation == 4:
        Operation4()
    elif operation == 5:
        Operation5()
    elif operation == 6:
        Operation6()
        
for row in A:
    for number in row:
        print(number, end=" ")
    print()