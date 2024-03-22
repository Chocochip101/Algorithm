import heapq

def solution(operations):
    q1=[]
    q2=[]

    for operation in operations:
        splited = operation.split()
        
        if splited[0]=='I':
            heapq.heappush(q1, int(splited[1]))
            heapq.heappush(q2, -int(splited[1]))
                          
        if len(q1) > 0 and operation == 'D 1':
            x = heapq.heappop(q2)
            q1.remove(-x)
                           
        if len(q2) > 0 and operation == 'D -1':
            x=heapq.heappop(q1)
            
            q2.remove(-x)

    if len(q1) == 0:
        return [0, 0]

    return [-heapq.heappop(q2), heapq.heappop(q1)]