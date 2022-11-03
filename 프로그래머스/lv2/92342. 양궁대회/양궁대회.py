from itertools import combinations_with_replacement
from collections import Counter
import copy
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
INF = 10**9


def solution(n, info):
    info = info[::-1]
    answer = []
    max_n = -1
    k = len(info)
    for c in combinations_with_replacement(range(0, k), n):
        ryan = 0
        apeach = 0
        tmp_ans = [0 for _ in range(k)]

        c = Counter(c)
        for i in range(0, k):
            if info[i] < c[i]:
                ryan += i
            elif info[i] != 0:
                apeach += i

            tmp_ans[i] = c[i]
        if ryan > apeach:
            diff = ryan - apeach
            if max_n < diff:
                max_n = diff
                answer = tmp_ans
    if answer:
        return answer[::-1]
    else:
        return [-1]
