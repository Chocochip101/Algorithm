from itertools import permutations

N = int(input())
K = int(input())

cards = []
for _ in range(N):
    cards.append(input())

num_set = set()

for it in permutations(cards, K):
    temp = ""
    for num in it: 
        temp += num
    num_set.add(temp)
print(len(num_set))