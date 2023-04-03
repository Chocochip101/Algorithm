from itertools import product
from collections import deque
import sys
import copy

N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]

def moveBoard(bb, d):
    new_b = [[0 for _ in range(N)] for _ in range(N)]
    if d == 0:
        for i in range(N):
            q = deque()
            prev = -1
            j = 0
            while j < N:
                if bb[i][j] != 0:
                    if prev == -1:
                        prev = bb[i][j]
                    else:
                        if bb[i][j] == prev:
                            q.append(prev * 2)
                            prev = -1
                        else:
                            q.append(prev)
                            prev = bb[i][j]
                    j += 1
                else:
                    j += 1
            
            if prev != -1:
                q.append(prev)
                
            j = 0
            while q:
                new_b[i][j] = q.popleft()
                j += 1
        return new_b
    
    elif d == 1:
        for i in range(N):
            q = deque()
            prev = -1
            j = N - 1
            while j >= 0:
                if bb[i][j] != 0:
                    if prev == -1:
                        prev = bb[i][j]
                    else:
                        if bb[i][j] == prev:
                            q.append(prev * 2)
                            prev = -1
                        else:
                            q.append(prev)
                            prev = bb[i][j]
                    j -= 1

                else:
                    j -= 1
            
            if prev != -1:
                q.append(prev)
                
            j = N - 1
            while q:
                new_b[i][j] = q.popleft()
                j -= 1
        return new_b
    
    elif d == 2:
        for j in range(N):
            q = deque()
            i = 0
            prev = -1

            while i < N:
                if bb[i][j] != 0:
                    if prev == -1:
                        prev = bb[i][j]
                    else:
                        if bb[i][j] == prev:
                            q.append(prev * 2)
                            prev = -1
                        else:
                            q.append(prev)
                            prev = bb[i][j]
                    i += 1

                else:
                    i += 1
            
            if prev != -1:
                q.append(prev)
            
            i = 0
            while q:
                new_b[i][j] = q.popleft()
                i += 1
        return new_b
    elif d == 3:
        for j in range(N):
            q = deque()
            i = N - 1
            
            prev = -1
            while i >= 0:
                if bb[i][j] != 0:
                    if prev == -1:
                        prev = bb[i][j]
                    else:
                        if bb[i][j] == prev:
                            q.append(prev * 2)
                            prev = -1
                        else:
                            q.append(prev)
                            prev = bb[i][j]
                    i -= 1

                else:
                    i -= 1
            
            if prev != -1:
                q.append(prev)
            i = N - 1
            while q:
                new_b[i][j] = q.popleft()
                i -= 1
        return new_b

def findMax(bb):
    res = 0
    for i in range(N):
        for j in range(N):
            res = max(res, bb[i][j])
    return res

ans = 0
for dd in product(range(4), repeat = 5):
    temp_b = copy.deepcopy(board)
    for d in dd:
        temp_b = moveBoard(temp_b, d)
        ans = max(ans, findMax(temp_b))
print(ans)
