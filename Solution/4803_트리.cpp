#include<bits/stdc++.h>
#define endl "\n"
#define MAX 502
#define INF 987654321
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M; 
vector<int> graph[MAX];
bool visited[MAX];
bool finished[MAX];

// Node 
int cntNode(int now){
    int cnt = 1;
    visited[now] = true;
    for(int next: graph[now])
        if(!visited[next])
            cnt += cntNode(next);
        
    return cnt;
}
// Edge
int cntEdge(int now){
    int cnt = graph[now].size();
    finished[now] = true;
    for(int next: graph[now])
        if(!finished[next])
            cnt += cntEdge(next);
    return cnt;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int tc = 0;
    while(1){
        tc++;
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
    
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        for(int i = 1; i <= N; ++i)
            graph[i].clear();
        
        for(int i = 0; i < M; ++i){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int res = 0;
        for(int i = 1; i <= N; ++i)
            if(!visited[i])
                if(cntEdge(i) / 2 == cntNode(i) - 1)
                    res++;


        cout << "Case " << tc << ":";
        if(res == 0)
            cout << " No trees."<< endl;
        else if(res == 1)
            cout << " There is one tree." << endl;
        else
            cout << " A forest of "<< res << " trees." << endl;
    }
	return 0;
}