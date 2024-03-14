from itertools import product
from collections import defaultdict
def solution(word):
    cList = ['A', 'E', 'I', 'O', 'U']
    words = []
    for p in product(cList):
        words.append("".join(p))
    for p in product(cList, cList):
        words.append("".join(p))
    for p in product(cList, cList, cList):
        words.append("".join(p))
    for p in product(cList, cList, cList, cList):
        words.append("".join(p))
    for p in product(cList, cList, cList, cList, cList):
        words.append("".join(p))
        
    words.sort()
    return words.index(word) + 1