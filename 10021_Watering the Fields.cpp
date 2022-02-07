#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 5001
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, C;
p points[2001];
vector<p> graph[2001];
struct Disjointset {
    vector<int> parent, rank;

    Disjointset(int n) : parent(n), rank(n + 1) {
        for (int i = 0l; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);

        if (u == v)return;
        if (rank[u] > rank[v]) swap(u, v);

        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};

int kruskal() {
    int ret = 0, cnt = 0;

    vector<pair<int, p>> edges;

    for(int u = 0; u < N; ++u )
        for (auto now : graph[u]) {
            int v = now.first; int cost = now.second;
            edges.push_back({ cost, {u, v} });
        }
    sort(edges.begin(), edges.end());

    Disjointset ds(N + 1);

    for (int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        if (cost < C) continue;
        int u = edges[i].second.first; int v = edges[i].second.second;

        if (ds.find(u) == ds.find(v)) continue;
        ds.merge(u, v);
        ret += cost;
        cnt++;
    }
    if (cnt != N - 1)
        ret = -1;
    return ret;
}

int dist(p a, p b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> points[i].first >> points[i].second;

    for(int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j) 
            graph[i].push_back({ j, dist(points[i], points[j]) });
        
    cout << kruskal() << endl;
    return 0;
}