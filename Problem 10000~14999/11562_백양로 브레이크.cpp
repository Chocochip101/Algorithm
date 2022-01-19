#include<bits/stdc++.h>
#define endl "\n"
#define MAX 251
#define INF 987654321
using namespace std;

int N, M;
int board[MAX][MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(&board[0][0], &board[MAX - 1][MAX], INF);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		board[i][i] = 0;

	for (int i = 0; i < M; ++i) {
		int u, v, b; cin >> u >> v >> b;
		if (b == 1) {
			board[u][v] = 0;
			board[v][u] = 0;
		}
		else {
			board[u][v] = 0;
			board[v][u] = 1;
		}
	}


	for (int t = 1; t <= N; ++t)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				board[i][j] = min(board[i][j], board[i][t] + board[t][j]);
					

	int K; cin >> K;
	for (int i = 0; i < K; ++i) {
		int s, e; cin >> s >> e;
		cout << board[s][e] << endl;
	}
	return 0;
}