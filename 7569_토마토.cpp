#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
using namespace std;
typedef pair<int, int> p;

struct ppp {
	int x, y, z;
};
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int H, N, M;
int board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
bool valid(int nx, int ny, int nz) { return 0 <= nx && nx < H && 0 <= ny && ny < N && 0 <= nz && nz < M; }
bool finished() {
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
				if (board[i][j][k] == 0)
					return false;
	return true;
}
int result() {
	int res = 0;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
				res = max(res, dist[i][j][k]);
	return res;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(dist, -1, sizeof(dist));
	queue<ppp> q;
	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push({ i, j, k });
					dist[i][j][k] = 0;
				}
			}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (valid(nx, ny, nz)) {
				if (dist[nx][ny][nz] == -1 && board[nx][ny][nz] == 0) {
					q.push({ nx, ny, nz });
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					board[nx][ny][nz] = 1;
				}

			}
		}
	}

	if (finished())
		cout << result() << endl;
	else
		cout << -1 << endl;
	return 0;
}