#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100000 + 1
using namespace std;
typedef pair<int, int> p;

int n, m;
int graph[101][101];
bool visited[101][101] = { false, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void bfs(int x, int y) {
	queue<p> q;
	visited[x][y] = true;
	q.push({ x, y });
	while (!q.empty()) {

		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (graph[nx][ny] == 1 && !visited[nx][ny]) {
					graph[nx][ny] = graph[x][y] + 1;
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j)
			graph[i][j] = s[j] - '0';
	}
	bfs(0, 0);
	cout << graph[n - 1][m - 1] << endl;
	return 0;
}