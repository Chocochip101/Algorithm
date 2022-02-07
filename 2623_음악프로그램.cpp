#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int ll
#define MAX  1001
#define INF 987654321
using namespace std;
typedef pair<int, int> p;

int n, m;
int indegree[MAX] = {0, };
bool passed[MAX];
vector<int> graph[MAX];

vector<int> topologySort() {
	queue<int> q;
	vector<int> res;
	for (int i = 1; i <= n; ++i)
		if (indegree[i] == 0) {
			q.push(i);
		}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		passed[now] = true;
		res.push_back(now);
		for (int next : graph[now]) {
			indegree[next]--;
			if (indegree[next] == 0 && !passed[next]) {
				q.push(next);
				passed[next] = true;
			}
		}
	}
	return res;
}
 signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(passed, false, sizeof(passed));
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int cnt; cin >> cnt;
		int prev, now;
		for (int i = 0; i < cnt; ++i) {
			
			if (i > 0) {
				prev = now;
				cin >> now;
				indegree[now]++;
				graph[prev].push_back(now);
			}
			else {
				cin >> now;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << indegree[i] << " ";
	cout << endl;
	vector<int> ans = topologySort();

	if (ans.size() == n)
		for (int a : ans)
			cout << a << endl;
	else cout << 0 << endl;
	return 0;
}