import sys
input = sys.stdin.readline

N, M = map(int, input().split())

numbers = list()
for i in range(N):
    numbers.append(int(input()))
numbers.sort()

left = 0
right = 0

answer = float('inf')

while left < N and right < N:
    if numbers[right] - numbers[left] == M:
        answer = M
        break
    elif numbers[right] - numbers[left] < M:
        right += 1
        continue
    answer = min(answer, numbers[right] - numbers[left])
    left += 1
        
print(answer)