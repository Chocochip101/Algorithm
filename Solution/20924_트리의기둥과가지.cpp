#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 200001
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, R;
vector<p> graph[MAX];
bool visited[MAX];
int B = -1;

int longestBranch(int now){
    visited[now] = true;
    int res = 0;
    for(int i = 0; i < graph[now].size(); ++i){
        int next = graph[now][i].first;
        int cost = graph[now][i].second;
        if(visited[next]) continue;
        res = max(res, cost + longestBranch(next));
    }
    return res;
}
int longestPole(int now){
    visited[now] = true;
    int res = 0;
    if(graph[R].size() == 2 || graph[now].size() > 2 || graph[now].size() == 0){
        B = now;
        return 0;
    }
    for(int i = 0; i < graph[now].size(); ++i)
        if(!visited[graph[now][i].first])
            res += (longestPole(graph[now][i].first) + graph[now][i].second);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(visited, false, sizeof(visited));
    cin >> N >> R;
    for(int i = 0; i < N - 1; ++i){
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    
    int p = longestPole(R);
    if(B == -1)
        B = R;
    int b = longestBranch(B);
    cout << p << " " << b << endl;
	return 0;
}