#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10001
#define INF 987654321
#define MOD 10001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
vector<int> graph[MAX];
set<int> st;
bool visited[MAX];
void dfs(int now){
    visited[now] = true;
    st.insert(now);
    for(int next:graph[now])
        if(!visited[next])
            dfs(next);
}
int dfs2(int now){
    visited[now] = true;
    if(st.find(now) != st.end())
        return now;
    for(int next: graph[now])
        if(!visited[next])
            return dfs2(next);
}
int solve(int a, int b){
    st.clear();
    memset(visited, false, sizeof(visited));
    dfs(a);
    memset(visited, false, sizeof(visited));
    return dfs2(b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--){
        cin >> N;
        for(int i = 0; i <= N; ++i)
            graph[i].clear();
        
        for(int i = 0; i < N - 1; ++i){
            int a, b; cin >> a >> b;
            graph[b].push_back(a);
        }
        int a, b; cin >> a>> b;
        cout << solve(a, b)<< endl;
    }
	return 0;
}