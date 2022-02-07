#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 1000000000
#define MAX 101
using namespace std;
typedef pair<int, int> p;

vector<int> adj[MAX];
bool visited[MAX];
int n, m;

int bfs(int src) {
	queue<int> q; q.push(src);
	int cnt = 0;
	while (!q.empty()) {

		if (visited[q.front()]) { q.pop(); continue; }
		cnt++;
		int now = q.front();
		visited[now] = true;
		q.pop();
		loop(i, adj[now].size()) {
			if (!visited[adj[now][i]])
				q.push(adj[now][i]);
		}
	}
	return cnt;
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
	memset(visited, false, sizeof(visited));
	cout << bfs(1) - 1 << endl;
	return 0;
}