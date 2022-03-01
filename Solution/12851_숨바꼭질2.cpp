#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 250001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, K;
bool visited[MAX];
int minSec = -1;
int bfs(){
    int ans = 0;
    queue<p> q;
    q.push({N, 0});
    visited[N] = true;

    while(!q.empty()){
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();
        visited[now] = true;
        if(minSec == dist && now == K)
            ans++;

        if(minSec == -1 && now == K){
            minSec = dist;
            ans++;
        }

        if(now - 1 >= 0 && !visited[now - 1]){
            q.push({now - 1., dist + 1});
        }
        if(now + 1 < MAX && !visited[now + 1]){
            q.push({now + 1., dist + 1});
        }
        if(now * 2 < MAX && !visited[now * 2]){
            q.push({now * 2., dist + 1});
        }
    }

    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(visited, false, sizeof(visited));
    cin >> N >> K;
    int ans = bfs();
    cout << minSec << endl << ans;
    return 0;
}