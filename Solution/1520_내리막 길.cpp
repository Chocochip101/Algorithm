#include <bits/stdc++.h>
#define endl "\n"
#define MAX  501
#define int long long
using namespace std;
typedef pair<int, int> p;
p Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int m, n;
int board[MAX][MAX];
int cache[MAX][MAX];

int dfs(int x, int y) {
	if (x == 0 && y == 0) return 1;

	int& ret = cache[x][y];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + Dir[i].first;
		int ny = y + Dir[i].second;

		if (0 <= nx && nx < m && 0 <= ny && ny < n) 
			if(board[nx][ny] > board[x][y])
				ret += dfs(nx, ny);
		
	}
	return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));

	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	cout << dfs(m - 1, n - 1) << endl;
	return 0;
}