#include<bits/stdc++.h>
#define MAX 1000001
#define endl "\n"
using namespace std;
typedef pair<int, int> p;
int N, K, M;

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

};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int i = 1; i <= tc; ++i) {
		cout << "Scenario " << i << ":" << endl;
		cin >> N >> K;
		DisjointSet ST(N);
		for (int j = 0; j < K; ++j) {
			int a, b; cin >> a >> b;
			ST.merge(a, b);
		}
		cin >> M;
		for (int j = 0; j < M; ++j) {
			int u, v; cin >> u >> v;
			if (ST.find(u) == ST.find(v))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		cout << endl;
	}
	return 0;
}