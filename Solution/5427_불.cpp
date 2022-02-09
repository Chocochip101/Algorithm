#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

p Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<p> fire;
bool valid(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y <= M;
}

int bfs(p src) {
	queue<p> q;
	queue<p> flame;
	visited[src.first][src.second] = true;
	q.push(src);

	for (p a : fire)
		flame.push(a);

	int res = 0;
	while (!q.empty()) {
		// Fire
		int ss = flame.size();
		for (int k = 0; k < ss; ++k) {
			int x = flame.front().first;
			int y = flame.front().second;
			flame.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + Dir[i].first;
				int ny = y + Dir[i].second;
				if (valid(nx, ny) && board[nx][ny] == 0) {
					board[nx][ny] = 1;
					flame.push({ nx, ny });
				}
			}

		}
		// Move
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == N - 1 || y == 0 || y == M - 1)
				return res + 1;

			for (int i = 0; i < 4; ++i) {
				int nx = x + Dir[i].first;
				int ny = y + Dir[i].second;

				if (valid(nx, ny) && !visited[nx][ny] && board[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
		res++;
	}
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char c;
	int tc; cin >> tc;
	p coord;
	while (tc--) {
		fire.clear();
		memset(visited, false, sizeof(visited));
		cin >> M >> N;
		for(int i = 0; i <N; ++i)
			for (int j = 0; j < M; ++j) {
				cin >> c;
				if (c == '#')
					board[i][j] = 2;

				else if (c == '.')
					board[i][j] = 0;

				else if (c == '*') {
					board[i][j] = 1;
					fire.push_back({ i, j });
				}

				else if (c == '@') {
					coord.first = i;
					coord.second = j;
					board[i][j] = 0;
				}
			}
		int result = bfs(coord);
		if (result == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;
	}

	return 0;
}