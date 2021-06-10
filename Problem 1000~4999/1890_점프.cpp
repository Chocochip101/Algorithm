#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int n;
ll board[101][101];
ll cache[101][101];
p Dir[2] = { {1, 0}, {0, 1} };

ll solve(int x, int y) {
	if (x == n - 1 && y == n - 1) return 1;

	ll& ret = cache[x][y];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 2; ++i) {
		int nx = x + board[x][y] * Dir[i].first;
		int ny = y + board[x][y] * Dir[i].second;
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
			ret += solve(nx, ny);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	memset(cache, -1, sizeof(cache));

	cout << solve(0, 0) << endl;
	return 0;
}