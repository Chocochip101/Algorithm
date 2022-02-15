#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
using namespace std;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
int dfs(int x){
    visited[x] = true;
    int res = 1;
    for(int next: graph[x]){
        if(!visited[next])
            res += dfs(next);
    }
    return res;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(visited, false, sizeof(visited));
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }
    int x; cin >> x;
    cout << dfs(x) - 1;
	return 0;
}