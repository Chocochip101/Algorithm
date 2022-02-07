#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 101
using namespace std;
typedef pair<int, int> p;

int n, m;
bool visited[MAX];
vector<int> family[MAX];

int bfs(int src, int dest) {
    queue<p> q;
    q.push({ src, 0 });
    visited[src] = true;
    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        visited[node] = true;
        if (node == dest) return dist;
        for (int temp : family[node]) {
            if (!visited[temp])
                q.push({ temp, dist + 1 });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n >> a >> b >> m;
    loop(i, m) {
        int x, y; cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    cout << bfs(a, b) << endl;
    return 0;
}