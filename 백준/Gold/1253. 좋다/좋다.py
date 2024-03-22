N = int(input())
numbers = list(map(int, input().split()))
numbers.sort()

answer = 0
for i in range(N):
    left = 0
    right = N - 1
    
    while left < right:
        if numbers[left] + numbers[right] == numbers[i]:
            if left == i:
                left += 1
            elif right == i:
                right -= 1
            else:
                answer += 1
                break
        elif numbers[left] + numbers[right] >= numbers[i]:
            right -= 1
        else:
            left += 1
print(answer)