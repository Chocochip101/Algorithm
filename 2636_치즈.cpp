#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 101
using namespace std; 
typedef pair<int, double> p;
p Dir[4] = { {1, 0}, {-1, 0}, {0, -1}, {0,1} };
int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cntCheeze() {
    int res = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 1)
                res++;
    return res;
}
bool valid(int nx, int ny) { return 0 <= nx && nx < N && 0 <= ny && ny < M; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    queue<p> q;
    int ans = 0;
    int prevCheeze = 0;
    while (cntCheeze() != 0) {

        prevCheeze = cntCheeze();
        ans++;
        memset(visited, false, sizeof(visited));
        q.push({ 0,0 });
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + Dir[i].first;
                int ny = y + Dir[i].second;
                if (valid(nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (board[nx][ny] == 0)
                        q.push({ nx, ny });
                    else if (board[nx][ny] == 1)
                        board[nx][ny] = 0;
                }
            }
        }

    }
    cout << ans << endl << prevCheeze << endl;
    return 0;
}