#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int n, m;
int board[501][501];
int cache[501][501];
p Dir[4] = { {1, 0},{-1, 0} , {0, 1},{0, -1} };

int solve(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;

	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + Dir[i].first;
		int ny = y + Dir[i].second;
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			if (board[nx][ny] < board[x][y])
				ret += solve(nx, ny);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	memset(cache, -1, sizeof(cache));

	cout << solve(0, 0) << endl;
	return 0;
}