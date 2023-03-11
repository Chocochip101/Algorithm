import sys
import math
sys.setrecursionlimit(10**8)
input = sys.stdin.readline
MAX = 2000010

isPrime = [True for _ in range(MAX)]
T = int(input())

def isPld(num):
    for i in range(len(num) // 2):
        if num[i] != num[len(num) - 1 - i]:
            return False
    return True

def Prime():
    isPrime[1] = False
    for i in range(2, int(math.sqrt(MAX))):
        if isPrime[i]:
            for j in range(i * 2, MAX, i):
                isPrime[j] = False

Prime()

while 1:
    if isPrime[T] and isPld(str(T)):
        print(T)
        exit()
    T += 1