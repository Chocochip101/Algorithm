import heapq
def solution(book_times):
    bookTime = []
    for book_time in book_times:
        sTime, eTime = book_time
        bookTime.append([toMinute(sTime), toMinute(eTime)])
        
    bookTime.sort(key = lambda x: (x[0], x[1]))

    q = []
    heapq.heappush(q, bookTime[0][1])
    answer = 1
    
    for i in range(1, len(bookTime)):
        minExitTime = heapq.heappop(q)
        if bookTime[i][0] < minExitTime + 10:
            heapq.heappush(q, bookTime[i][1])
            heapq.heappush(q, minExitTime)
            answer += 1
        else:
            heapq.heappush(q, bookTime[i][1])
            
            
    return answer

def toMinute(book_time):
    book_time = book_time.split(":")
    return int(book_time[0]) * 60 + int(book_time[1])