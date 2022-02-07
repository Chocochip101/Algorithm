#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
#define int ll
using namespace std;
typedef pair<int, int> p;
int N, M;
// cost node node
vector<pair<int, p>> edges;
struct DisjointSet {
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n + 1) {
		for (int i = 0l; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = parent[u]; v = parent[v];
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int kruskal() {
	int res = 0;
	sort(edges.begin(), edges.end());

	DisjointSet sets(N + 1);
	vector<int> costs;
	for (int i = 0; i < edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first; int v = edges[i].second.second;

		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		costs.push_back(cost);
		res += cost;

	}
	if (costs.size() != N - 1)
		return -1;

	return res;

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	edges.resize(M);
	int total = 0;
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		edges[i].first = c;
		edges[i].second.first = a;
		edges[i].second.second = b;
		total += c;

	}
	int ans = kruskal();
	if (ans == -1)
		cout << ans;
	else
		cout << total - kruskal();
	return 0;
}