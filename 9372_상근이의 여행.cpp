#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M;
bool visited[MAX];
bool graph[MAX][MAX];
int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int ans = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next = 1; next <= N; ++next) {
            if (graph[now][next] && !visited[next]) {
                visited[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        memset(visited, false, sizeof(visited));
        memset(graph, false, sizeof(graph));

        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            int a, b; cin >> a >> b;
            graph[a][b] = true;
            graph[b][a] = true;
        }
        cout << bfs() << endl;

    }
    return 0;
}