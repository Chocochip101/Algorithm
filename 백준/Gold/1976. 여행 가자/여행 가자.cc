#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 32000 + 1
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
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	int schedule[1001];

	DisjointSet solve(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int temp; cin >> temp;
			if (temp == 1) solve.merge(i, j);
		}
	}

	for (int i = 0; i < m; ++i) cin >> schedule[i];

	int pivot = solve.find(schedule[0]);
	bool isFail = false;

	for (int i = 1; i < m; ++i) {
		if (solve.find(schedule[i]) != pivot)
			isFail = true;
	}

	if (!isFail) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}