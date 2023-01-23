import math

def solution(n):
    if n == int(math.sqrt(n)) ** 2:
        return (int(math.sqrt(n)) + 1) ** 2
    return -1