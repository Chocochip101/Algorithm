import sys

T = int(input())
for _ in range(T):
    N = int(input())
    nums1 = set(map(int, input().split()))
    
    M = int(input())
    nums2 = list(map(int, input().split()))
    for i in range(M):
        if nums2[i] in nums1:
            print(1)
        else:
            print(0)