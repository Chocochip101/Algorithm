#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int triangle[501][501];
int cache[501][501];
int solve(int y, int x) {
	//Base
	if (y == n - 1) return triangle[y][x];

	//Memoization
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(solve(y + 1, x + 1), solve(y + 1, x)) + triangle[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			cin >> triangle[i][j];
	memset(cache, -1, sizeof(cache));
	cout << solve(0, 0) << endl;
	return 0;
}