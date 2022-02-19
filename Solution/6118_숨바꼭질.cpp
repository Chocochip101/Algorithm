#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 20001
using namespace std;
typedef pair<int, double> p;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> ans;
int maxCost = 0;
void bfs(int src){
    queue<p> q;
    q.push({src, 0});
    visited[src] = true;
    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int next: graph[now]){
            if(!visited[next]){
                if(maxCost < cost + 1){
                    maxCost = cost + 1;
                    ans.clear();
                    ans.push_back(next);
                }
                else if(maxCost == cost + 1){
                    ans.push_back(next);
                }
                q.push({next, cost + 1});
                visited[next] = true;
            }
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << maxCost << " " <<ans.size() << endl;
    return 0;
}