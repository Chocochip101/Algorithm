def solution(friends, gifts):
    # A가 선물을 받음
    receivedGifts = [[0 for _ in range(len(friends))]for _ in range(len(friends))]
    for gift in gifts :
        n1, n2 = gift.split()
        receivedGifts[friends.index(n2)][friends.index(n1)] += 1
        
    nextMonth = [0 for _ in range(len(friends))]
    
    for i in range(len(friends)):
        for j in range(i + 1, len(friends)):
            if receivedGifts[i][j] > receivedGifts[j][i]:
                nextMonth[j] += 1
            elif receivedGifts[i][j] < receivedGifts[j][i]:
                nextMonth[i] += 1
            if receivedGifts[i][j] == receivedGifts[j][i]:
                iPoints = calcPresentPoints(i, receivedGifts)
                jPoints = calcPresentPoints(j, receivedGifts)
                if iPoints > jPoints:
                    nextMonth[i] += 1
                elif iPoints < jPoints:
                    nextMonth[j] += 1
    answer = 0
    for i in range(len(friends)):
        answer = max(answer, nextMonth[i])
    return answer

def calcPresentPoints(fIndex, receivedGifts):
    givePresentCnt = 0
    receivedPresentCnt = 0
    for i in range(len(receivedGifts)):
        if i == fIndex:
            continue
        givePresentCnt += receivedGifts[i][fIndex]
        receivedPresentCnt += receivedGifts[fIndex][i]
    return givePresentCnt - receivedPresentCnt