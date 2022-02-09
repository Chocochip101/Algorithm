#include<bits/stdc++.h>
#define ll long long
#define MAX 51
using namespace std; 
typedef pair<int, double> p;

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
    int N, M;
    cin >> N >> M;

    DisjointSet sets(N + 1);
	vector<int> truth;
    int x; cin >> x;
	for (int i = 0; i < x; ++i) {
		int a; cin >> a;
		truth.push_back(a);
	}
	vector<int> PARTY[MAX];
	for (int i = 0; i < M; ++i) {
		int a; cin >> a;
		for (int j = 1; j <= a ; ++j) {
			int b; cin >> b;
			PARTY[i].push_back(b);
		}
	}
	
	for (int i = 0; i < M; ++i) {
		if (PARTY[i].size() == 0) continue;
		int now = PARTY[i][0];
		for (int j = 1; j < PARTY[i].size(); ++j)
			sets.merge(now, PARTY[i][j]);
	}
	
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		bool isTrue = true;
		for (int j = 0; j < truth.size(); ++j)
			if (sets.find(PARTY[i][0]) == sets.find(truth[j]))
				isTrue = false;
		if (isTrue)
			ans++;
	}
	cout << ans;
    return 0;
}