#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int n, m;
vector<p> adj[MAX];
int trace[MAX];
vector<int> dijkstra(int src) {
    vector<int> dist(n + 1, INF);
    dist[src] = 0;

    priority_queue<p> pq;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (dist[now] < cost) continue;
        for (auto next : adj[now]) {
            int nextDist = cost + next.second;

            if (dist[next.first] > nextDist) {
                dist[next.first] = nextDist;
                pq.push({ -nextDist, next.first });
                trace[next.first] = now;
            }
        }
    }
    return dist;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    int src, dest; cin >> src >> dest;
    cout << dijkstra(src)[dest] << endl;


    vector<int> ans;
    while (dest) {
        ans.push_back(dest);
        dest = trace[dest];
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[ans.size() - i - 1] << " ";
    return 0;
}