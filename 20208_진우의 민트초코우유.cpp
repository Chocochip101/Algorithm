#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
using namespace std;
typedef pair<int, int> p;

int N, M, H;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<p> mint;
int ans = 0;
int hx, hy;
int dist(int x, int y, int nx, int ny) { return abs(x - nx) + abs(y - ny); }
void dfs(int x, int y, int hp, int cnt) {
	for (p next : mint) {
		if (dist(x, y, next.first, next.second) <= hp && !visited[next.first][next.second]) {
			
			visited[next.first][next.second] = true;
			if(dist(hx, hy, next.first, next.second) <= hp - dist(x, y, next.first, next.second) + H)
				ans = max(ans, cnt + 1);
			dfs(next.first, next.second, hp - dist(x, y, next.first, next.second) + H, cnt + 1);
			visited[next.first][next.second] = false;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(visited, false, sizeof(visited));
	cin >> N >> M >> H;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				mint.push_back({ i, j });
			else if (board[i][j] == 1) {
				board[i][j] = 0;
				hx = i; hy = j;
			}
		}

	dfs(hx, hy, M, 0);
	cout << ans << endl;
	return 0;
}