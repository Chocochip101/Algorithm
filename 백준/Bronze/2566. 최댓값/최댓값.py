matrix = [list(map(int,input().split())) for _ in range(9) ]
maximum = -1

for i in range(9):
    for j in range(9):
        if maximum < matrix[i][j]:
            maximum = matrix[i][j]
            a = i+1
            b = j+1
print(maximum)
print(a, b)