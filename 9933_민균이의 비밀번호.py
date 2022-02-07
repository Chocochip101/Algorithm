n = int(input())

word = []
for _ in range(n):
    temp = input().rstrip()
    word.append(temp)

ans = ''
for w in word:
    if w[::-1] in word:
        ans = w
        break
print(len(ans), ans[(len(ans) - 1 )// 2])