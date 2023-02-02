import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

S = input().rstrip()

def countCroatia(s):
    cnt = 0
    i = 0
    while i < len(s):
        if s[i: i + 2] == 'c=':
            cnt += 1
            i += 2
        elif s[i:i + 2] == 'c-':
            cnt += 1
            i += 2
        elif s[i:i + 3] == 'dz=':
            cnt += 1
            i += 3
        elif s[i:i + 2] == 'd-':
            cnt += 1
            i += 2
        elif s[i:i + 2] == 'lj':
            cnt += 1
            i += 2
        elif s[i:i + 2] == 'nj':
            cnt += 1
            i += 2
        elif s[i:i + 2] == 's=':
            cnt += 1
            i += 2
        elif s[i:i + 2] == 'z=':
            cnt += 1
            i += 2
        else:
            cnt += 1
            i += 1
    return cnt

print(countCroatia(S))