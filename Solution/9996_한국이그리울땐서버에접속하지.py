import sys
input = sys.stdin.readline

N = int(input())
f_str, b_str = input().split('*')

def solve(s):

    if f_str == s[:len(f_str)] and b_str == s[-len(b_str):] and len(f_str + b_str) <= len(s):
        return True
    else: 
        return False

for i in range(N):
    s = input()
    if solve(s):
        print("DA")
    else:
        print("NE")