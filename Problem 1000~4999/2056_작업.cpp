#include <bits/stdc++.h>
#define endl "\n"
#define MAX  10001
using namespace std;
typedef pair<int, int> p;

int n;
int Times[MAX];
vector<int> graph[MAX];
int indegree[MAX] = {0, };
int cache[MAX];

int bfs() {
	int res = 0;
	queue<int> q;

	for(int i = 1;i <=n; ++i)
		if (!indegree[i]) {
			cache[i] = Times[i];
			q.push(i);
		}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			indegree[next]--;
			if (!indegree[next]) {
				q.push(next);
			}

			cache[next] = max(cache[next], cache[now] + Times[next]);
		}
	}

	for (int i = 1; i <= n; ++i)
		res = max(res, cache[i]);

	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> Times[i];
		int  k; cin>> k;
		while (k--) {
			int a; cin >> a;
			graph[a].push_back(i);
			indegree[i]++;
		}
	}

	cout << bfs() << endl;
	return 0;
}