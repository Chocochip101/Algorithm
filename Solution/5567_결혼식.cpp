#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 1000000000
#define MAX 501
using namespace std;
typedef pair<int, int> p;

vector<int> adj[MAX];
bool visited[MAX];
int dist[MAX] = { 0, };
int n, m;
void bfs(int src) {
	queue<int> q;
	visited[src] = true;
	q.push(src);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		loop(i, adj[now].size()) {
			int there = adj[now][i];
			if (!visited[there]) {
				dist[there] = dist[now] + 1;
				visited[there] = true;
				q.push(there);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	loop(i, m) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	int res = 0;
	for (int i = 1; i <= n; ++i)
		if (0 < dist[i] && dist[i] <= 2)
			res++;
	cout << res << endl;
	return 0;
}