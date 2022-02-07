#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int n, m;
int board[1001][1001];
int cache[1001][1001];
p Dir[3] = { {1, 0} , {0, 1},{1, 1} };

int solve(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = board[x][y];
	return ret += max(max(solve(x + 1, y), solve(x + 1, y + 1)), solve(x, y + 1));
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