#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX_V 200 + 1
using namespace std;
typedef pair<int, int> p;
int n;
int board[MAX_V][MAX_V];
int dx[6] = { -2,-2,  0, 0 , 2, 2 };
int dy[6] = { -1, 1,  -2, 2 , -1, 1 };
void bfs(int r1, int c1, int r2, int c2) {
    queue<p> q;
    q.push({ r1, c1 });
    board[r1][c1] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        loop(i, 6) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != -1) continue;
            board[nx][ny] = board[x][y] + 1;
            q.push({ nx, ny });
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    memset(board, -1, sizeof(board));
    bfs(r1, c1, r2, c2);
    cout << board[r2][c2] << endl;
    return 0;
}