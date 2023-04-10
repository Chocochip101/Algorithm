
def solution(arr):
    answer = []
    prev = -1
    for i in range(len(arr)):
        if prev == -1:
            answer.append(arr[i])
            prev = arr[i]
        else:
            if prev == arr[i]:
                continue
            else:
                answer.append(arr[i])
                prev = arr[i]
    return answer