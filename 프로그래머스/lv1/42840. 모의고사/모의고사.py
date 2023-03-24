def solution(answers):
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    one_c = 0
    two_c = 0
    three_c = 0
    
    for i in range(len(answers)):
        if answers[i] == one[i % len(one)]:
            one_c += 1
        if answers[i] == two[i % len(two)]:
            two_c += 1
        if answers[i] == three[i % len(three)]:
            three_c += 1
    
    m = max(one_c, two_c, three_c)
    answer = []
    if m == one_c:
        answer.append(1)
    if m == two_c:
        answer.append(2)
    if m == three_c:
        answer.append(3)
    return answer