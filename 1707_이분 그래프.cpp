#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 20000+1
using namespace std;
typedef pair<int, int> p;

bool ans = false;
int dist[MAX];
void bfs(int src, vector<int> graph[MAX]) {
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int temp : graph[now]) {
			if (dist[temp] == dist[now]) {
				ans = true;

			}
			else if (dist[temp] == -1) {
				dist[temp] = (dist[now] == 0) ? 1 : 0;
				q.push(temp);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		vector<int> graph[MAX];
		memset(dist, -1, sizeof(dist));
		int v, e;
		ans = false;
		cin >> v >> e;
		loop(i, e) {
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		for (int i = 1; i <= v; ++i)
			if (dist[i] == -1)
				bfs(i, graph);

		if (!ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}