#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 32001
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;
struct coords {
	int x1, y1, x2, y2;
};

int n;
vector<coords> coord;

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

	bool meet(int u, int v) {
		coords a = coord[u];
		coords b = coord[v];
		if (b.y2 > a.y2 && a.x2 < b.x2 && a.y1 > b.y1 && b.x1 < a.x1)
			return false;
		if (a.y2 > b.y2 && b.x2 < a.x2 && b.y1 > a.y1 && b.x1 > a.x1)
			return false;
		if (b.y1 > a.y2 || b.x1 > a.x2 || a.y1 > b.y2 || b.x2 < a.x1)
			return false;
		return true;
	}
};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	DisjointSet ds(n + 1);
	coord.push_back({ 0, 0, 0, 0 });
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		coord.push_back({ x1, y1, x2, y2 });
	}

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (ds.meet(i, j)) {
				ds.merge(i, j);
			}
	set<int> s;
	for (int i = 0; i <= n; ++i) 
		s.insert(ds.find(i));
	
	cout << s.size() - 1 << endl;
	return 0;
}
