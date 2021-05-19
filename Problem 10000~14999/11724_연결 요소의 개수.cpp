#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 1000000000
#define MAX 1001
using namespace std;
typedef pair<int, int> p;

vector<int> adj[MAX];
bool visited[MAX];
int n, m;
void dfs(int src) {
	visited[src] = true;
	for (int i = 0; i < adj[src].size(); ++i) {
		if (!visited[adj[src][i]])
			dfs(adj[src][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	loop(i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
	return 0;
}