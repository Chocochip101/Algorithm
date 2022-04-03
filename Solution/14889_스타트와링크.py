from itertools import combinations
def score(ll, board):
    res = 0
    for i in range(len(ll)):
        for j in range(i + 1, len(ll)):
            res += board[ll[i] - 1][ll[j] - 1]
            res += board[ll[j] - 1][ll[i] - 1]
    return res

if __name__ == '__main__':
    N = int(input())
    board = []
    for i in range(N):
        board.append(list(map(int, input().split())))

    a = list(i for i in range(1, N + 1))
    ans = 987654321
    for li in combinations(a, N // 2):
        fir = score(li, board)
        temp = [i for i in range(1, N + 1) if i not in li]
        sec = score(temp, board)
        ans = min(abs(fir - sec), ans)
    print(ans)
        