#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 126
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

int n;
int board[MAX][MAX]; 
int dist[MAX][MAX];
p Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INF;

	queue<p> q;
	q.push({ 0, 0 });
	dist[0][0] = board[0][0];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + Dir[i].first;
			int ny = y + Dir[i].second;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// 비용이 더 클 경우, update
				if (dist[nx][ny] > dist[x][y] + board[nx][ny]) {
					dist[nx][ny] = dist[x][y] + board[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
	}
	return dist[n - 1][n - 1];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc = 1;
	while (++tc) {
		cin >> n;
		if (n== 0) break;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> board[i][j];
		cout << "Problem " << tc - 1 << ": " << bfs() << endl;
	}
	return 0;
}