import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = set(map(int, input().split()))
B = set(map(int, input().split()))
x = A.intersection(B)
print(len(A) + len(B) - 2 * len(x))
