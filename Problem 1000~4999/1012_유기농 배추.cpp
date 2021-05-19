#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
using namespace std;
typedef pair<int, int> p;

int board[51][51];
bool visited[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, k;
void dfs(int x, int y) {

	visited[x][y] = true;
	loop(i, 4) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (board[nx][ny] == 1 && !visited[nx][ny]) {
				dfs(nx, ny);

			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int res = 0;
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		cin >> m >> n >> k;
		loop(i, k) {
			int x, y; cin >> x >> y;
			board[y][x] = 1;
		}
		loop(i, n)
			loop(j, m) {
			if (board[i][j] == 1 && visited[i][j] == false) {
				dfs(i, j);
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}