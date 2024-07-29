import sys
input = sys.stdin.readline

N = int(input())
cards = set(map(int, input().split()))
M = int(input())
finds = map(int, input().split())

answers = []
for toFind in finds:
    if toFind in cards:
        answers.append(1)
    else:
        answers.append(0)

for answer in answers:
    print(answer, end=" ")