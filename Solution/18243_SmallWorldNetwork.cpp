#include<bits/stdc++.h>
#define endl "\n"
#define MAX 101
#define INF 987654321
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, K;
vector<int> graph[MAX];
int dist[MAX];
bool finished(){
    for(int i = 1; i <= N; ++i)
        if(dist[i] == -1 || dist[i] >= 7)
            return false;
    return true;
}
void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next: graph[now])
            if(dist[next]== -1){
                q.push(next);
                dist[next] = dist[now] + 1;
            }
    }
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i < K; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i){
        memset(dist, -1, sizeof(dist));
        bfs(i);

        if(!finished()){
            cout << "Big World!";
            return 0;
        }
    }
    cout << "Small World!";
	return 0;
}