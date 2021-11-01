#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
p Dir[4] = { {1, 0}, {-1, 0}, {0  ,1}, {0, -1} };

int N, M;
vector<string> board;
bool visited[MAX][MAX];

void dfs(int x, int y) {
    visited[x][y] = true;
   
    for (int i = 0; i < 4; ++i) {
        int nx = x + Dir[i].first;
        int ny = y + Dir[i].second;
        if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny] && (board[nx][ny] == '0'))
            dfs(nx, ny);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N>> M;
    board.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    bool canGo = false;
    for (int j = 0; j < M; ++j) {
        if (board[0][j] == '0' && !visited[0][j])
            dfs(0, j);
    }

    for (int j = 0; j < M; ++j)
        if (visited[N - 1][j])
            canGo = true;
    
    if (canGo)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}