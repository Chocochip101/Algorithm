#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 31
using namespace std;
typedef pair<int, int> p;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1 ,0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
struct ppp {
	int x, y, z;
};
int L, R, C;
char board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
ppp src, dest;
bool valid(int x, int y, int z) { return 0 <= x && x < L && 0 <= y && y < R && 0 <= z && z < C; }
int bfs() {
	queue<ppp> q;
	q.push(src);

	dist[src.x][src.y][src.z] = 0;

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
				if (dest.x == nx && dest.y == ny && dest.z == nz) {
					return dist[x][y][z] + 1;
				}
				else if(dist[nx][ny][nz] == -1 && board[nx][ny][nz] == '.'){
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					q.push({ nx, ny, nz });
				}
			}
		}
	}

	return -1;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		memset(dist, -1, sizeof(dist));
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				for (int k = 0; k < C; ++k) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						src.x = i; src.y = j; src.z = k;
					}
					else if (board[i][j][k] == 'E') {
						dest.x = i; dest.y = j; dest.z = k;
					}
				}
		int res = bfs();
		if (res == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << res << " minute(s)." << endl;
	}
	return 0;
}