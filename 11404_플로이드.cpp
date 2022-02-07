#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define INF 987654321
using namespace std;
int graph[101][101];
int main() {
	int n; cin >> n;
	int m; cin >> m;
	int a, b, c;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			graph[i][j] = INF;

	while (m--) {
		cin >> a >> b >> c;
		if (graph[a - 1][b - 1] == INF)
			graph[a - 1][b - 1] = c;
		else
			graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
	}

	for (int i = 0; i < n; ++i) graph[i][i] = 0;

	for (int t = 0; t < n; t++)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j]);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}cout << endl;
	}
	return 0;
}