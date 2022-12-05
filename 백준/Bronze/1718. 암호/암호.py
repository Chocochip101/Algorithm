def alphaToNum(c):
    return ord(c) - ord('a')

def NumToAlpah(n):
    return chr(n + 97)

sent = input().rstrip()
sec_key = input().rstrip()

ans = ''
for i in range(len(sent)):
    if sent[i] == ' ':
        ans += ' '
        continue
    now = alphaToNum(sent[i]) - alphaToNum(sec_key[i % len(sec_key)]) - 1
    if now < 0:
        now += 26
    ans += NumToAlpah(now)

print(ans)