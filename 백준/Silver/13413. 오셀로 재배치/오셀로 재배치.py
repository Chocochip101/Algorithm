import sys
sys = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    init = input().rstrip()
    dest = input().rstrip()
    w_c = 0
    b_c = 0
    for i in range(N):
        if init[i] != dest[i]:
            if init[i] == 'W':
                w_c += 1
            else:
                b_c += 1
    print(max(w_c, b_c))