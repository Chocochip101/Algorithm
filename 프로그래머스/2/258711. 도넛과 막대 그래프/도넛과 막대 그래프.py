from collections import defaultdict

def solution(edges):
    answer = [0, 0, 0, 0]

    nodes = set()
    given = defaultdict(int)
    received = defaultdict(int)
    
    for a, b in edges:
        given[a] += 1
        received[b] += 1
        nodes.add(a)
        nodes.add(b)
        
    for node in nodes:
        if given[node] >= 2 and received[node] == 0:
            answer[0] = node
        elif given[node] == 0 and received[node]> 0:
            answer[2] += 1
        elif given[node] >= 2 and received[node] >= 2:
            answer[3] += 1
    
    answer[1] = (given[answer[0]] - answer[2] - answer[3])

    return answer