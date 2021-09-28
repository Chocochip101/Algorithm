#include <bits/stdc++.h>
#define endl "\n"
#define MAX  5000001
using namespace std;
typedef pair<int, int> p;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) :parent(n), rank(n + 1) {
		for (int i = 0l; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u); v = find(v);

		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
	bool isSame(int b, int c) {
		if (find(b) == find(c))
			return true;
		else return false;
	}
};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	DisjointSet ds(n + 1);

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		if (ds.isSame(a, b)) {
			ans = i + 1;
			break;
		}
		else {
			ds.merge(a, b);
		}
	}

	cout << ans << endl;
}