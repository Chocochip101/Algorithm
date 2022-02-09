#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 401
using namespace std;
typedef pair<int, int> p;

int V, E;
int board[MAX][MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			board[i][j] = INF;

	for (int i = 0; i < E; ++i) {
		int a, b, c; cin >> a >> b >> c;
		board[a][b] = c;
	}

	for (int t = 1; t <= V; ++t)
		for (int i = 1; i <= V; ++i)
			for (int j = 1; j <= V; ++j)
				if (board[i][t] != INF && board[t][j] != INF)
					board[i][j] = min(board[i][j], board[i][t] + board[t][j]);

	int ans = INF;
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			if (board[i][j] != INF && board[j][i] != INF)
				ans = min(ans, board[i][j] + board[j][i]);
	if (ans >= INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}