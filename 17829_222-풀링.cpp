#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
int board[MAX][MAX];

int solve(int sr, int er, int sc, int ec) {
	if (sr + 1 == er && sc + 1 == ec) return board[sr][sc];

	vector<int> res;
	res.push_back(solve(sr, (sr + er) / 2, sc, (sc + ec) / 2));
	res.push_back(solve((sr + er) / 2, er, sc, (sc + ec) / 2));
	res.push_back(solve(sr, (sr + er) / 2, (sc + ec) / 2, ec));
	res.push_back(solve((sr + er) / 2, er, (sc + ec) / 2, ec));

	sort(res.begin(), res.end());
	return res[2];
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	cout << solve(0, N, 0, N);
	return 0;
}