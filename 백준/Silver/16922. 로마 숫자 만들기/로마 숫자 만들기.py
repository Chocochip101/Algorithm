from itertools import combinations_with_replacement

N = int(input())
res = set()

for cm in combinations_with_replacement([1, 5, 10, 50], N):
    res.add(sum(cm))
print(len(res))