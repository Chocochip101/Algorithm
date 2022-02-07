#include <bits/stdc++.h>
#define endl "\n"
#define MAX  1001
using namespace std;
typedef pair<int, int> p;

int n, k;
int w;
int buildingTime[MAX];
int indegree[MAX] = { 0, };
bool graph[MAX][MAX];
int cache[MAX];

int solve(int now) {
	int& ret = cache[now];
	if (ret != -1) return ret;

	int t = 0;
	for (int i = 1; i <= n; ++i)
		if (graph[now][i])
			t = max(t, solve(i));

	return ret = t + buildingTime[now];
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		memset(graph, false, sizeof(graph));
		memset(cache, -1, sizeof(cache));
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> buildingTime[i];
		for (int i = 0; i < k; ++k) {
			int x, y; cin >> x >> y;
			indegree[y]++;
		}
		cin >> w;
		cout << solve(w) << endl;
	}
	return 0;
}