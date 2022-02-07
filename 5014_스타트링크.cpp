#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1000001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int F, S, G, U, D;
bool visited[MAX];
int bfs() {
    memset(visited, false, sizeof(visited));

    queue<p> q;
    q.push({ S, 0 });
    visited[S] = true;
    while (!q.empty()) {
        int now = q.front().first; 
        int cnt = q.front().second;
        q.pop();

        if (now == G) return cnt;

        if (now + U <= F && !visited[now  + U]) {
            q.push({ now + U, cnt + 1 });
            visited[now + U] = true;
        }
        if (now - D >= 1 && !visited[now - D]) {
            q.push({ now - D, cnt + 1 });
            visited[now - D] = true;
        }

    }
    return -1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // S to G
    cin >> F >> S >> G >> U >> D;
    int ans = bfs();
    if (ans == -1)
        cout << "use the stairs" << endl;
    else cout << ans;
    return 0;
}