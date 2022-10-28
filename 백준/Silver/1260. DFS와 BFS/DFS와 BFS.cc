#include <bits/stdc++.h>
#define endl "\n"
#define INF 987654321
using namespace std;
int n, m, v;
vector<vector<int>> adj(1001);
vector<bool> visited(1001, false);
queue<int> q;

void dfs(int start) {
	visited[start] = true;
	cout << start << " ";
	for(int i : adj[start])
		if (!visited[i]) {
			dfs(i);
		}
}
void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		cout << start << " ";
		for(int y : adj[start])
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >>m >> v;
	int s, e;
	for (int i = 0; i < m; ++i) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	dfs(v);
	cout << endl;
	visited = vector<bool>(1001, false);
	bfs(v);
	return 0;
}