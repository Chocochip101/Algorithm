s1 = input().rstrip()
s2 = input().rstrip()

s1, s2 = s1 * len(s2), s2 * len(s1)

if s1 == s2:
    print(1)
else:
    print(0)