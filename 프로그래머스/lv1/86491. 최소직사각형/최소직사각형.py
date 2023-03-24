import sys
sys.setrecursionlimit(10**8)

msize = float('inf')
def solve(idx, sizes, h, w):
    if idx == len(sizes):
        global msize
        msize = min(msize, h * w)
        return
    if (sizes[idx][0] <= h and sizes[idx][1] <= w) or  (sizes[idx][1] <= h and sizes[idx][0] <= w):
        solve(idx + 1, sizes, h, w)
    else:
        solve(idx + 1, sizes, max(h, sizes[idx][1]), max(w, sizes[idx][0]))
        solve(idx + 1, sizes, max(h, sizes[idx][0]), max(w, sizes[idx][1]))

def solution(sizes):
    solve(0, sizes, sizes[0][0], sizes[0][1])
    global msize
    return msize