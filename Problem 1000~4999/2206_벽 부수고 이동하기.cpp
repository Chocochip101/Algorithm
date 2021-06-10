#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 1001
using namespace std;
typedef pair<int, int> p;

p Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m;
vector<string> board;
int dist[MAX][MAX][2];

int bfs(int x, int y) {

	dist[x][y][1] = 1;
	queue<pair<p, int>> q;
	q.push({ {x, y}, 1 });

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int block = q.front().second;
		if (x == n - 1 && y == m - 1) return dist[x][y][block];
		q.pop();

		loop(i, 4) {
			int nx = x + Dir[i].first;
			int ny = y + Dir[i].second;
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[nx][ny] == '0' && dist[nx][ny][block] == 0) {
					dist[nx][ny][block] = dist[x][y][block] + 1;
					q.push({ {nx, ny}, block });

				}
				else if (board[nx][ny] == '1' && block) {

					dist[nx][ny][block - 1] = dist[x][y][block] + 1;
					q.push({ {nx, ny}, block - 1 });

				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	board.resize(n);

	loop(i, n) cin >> board[i];
	cout << bfs(0, 0) << endl;
	return 0;
}