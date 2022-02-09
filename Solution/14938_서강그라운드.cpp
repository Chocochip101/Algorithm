#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 126
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M, R;
int items[101];
int graph[101][101];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; ++i)
		cin >> items[i];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			if (i == j) graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}

	for (int i = 1; i <= R; ++i)
	{
		int a, b, l; cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}

	for (int t = 1; t <= N; ++t)
		for (int i = 1; i < N; ++i)
			for (int j = 1; j <= N; ++j)
				if (graph[i][t] < INF && graph[t][i] < INF)
					graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j]);


	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int temp = 0;
		for (int j = 1; j <= N; ++j)
			if (graph[i][j] <= M)
				temp += items[j];
		ans = max(temp, ans);
	}
	cout << ans << endl;
	return 0;
}