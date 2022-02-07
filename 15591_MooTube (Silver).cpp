#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 5001
#define int ll
using namespace std;
typedef pair<int, int> p;
//node, cost
vector<p> graph[MAX];
bool visited[MAX];

int bfs(int k, int v) {
    memset(visited, false, sizeof(visited));
    visited[v] = true;

    int ans = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto a : graph[now])
            if (!visited[a.first] && a.second >= k) {
                q.push(a.first);
                visited[a.first] = true;
                ans++;
            }
    }
    return ans;
}
int N, Q;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;

    for (int i = 0; i < N - 1; ++i) {
        int p, q, r; cin >> p >> q >> r;
        graph[p].push_back({ q, r });
        graph[q].push_back({ p, r });
    }

    for (int i = 0; i < Q; ++i) {
        int k, v; cin >> k >> v;
        cout << bfs(k, v) << endl;
    }
    return 0;
}