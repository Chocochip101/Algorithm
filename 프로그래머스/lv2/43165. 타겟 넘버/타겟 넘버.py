answer = 0


def solve(numbers, idx, res, target):
    if idx == len(numbers):
        if res == target:
            global answer
            answer += 1
        return
    solve(numbers, idx + 1, res + numbers[idx], target)
    solve(numbers, idx + 1, res - numbers[idx], target)

def solution(numbers, target):
    solve(numbers, 0, 0, target)
    global answer
    return answer