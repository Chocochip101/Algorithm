#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 51
using namespace std;
typedef pair<int, int> p;
int w, h;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cnt = 0;
int dx[8] = { -1, 1, 0, 0 , 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1 , 1, -1, 1, -1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    loop(i, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w) {
            if (board[x][y] == board[nx][ny] && !visited[nx][ny])
                dfs(nx, ny);
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true) {
        cin >> w >> h;
        cnt = 0;
        if (!w && !h) break;
        memset(visited, false, sizeof(visited));
        loop(i, h)
            loop(j, w)
            cin >> board[i][j];
        loop(i, h)
            loop(j, w)
            if (board[i][j] == 1 && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
        cout << cnt << endl;
    }
    return 0;
}
