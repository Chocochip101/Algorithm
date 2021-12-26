#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 120
using namespace std; 
typedef pair<int, double> p;

int N;
bool visited[MAX];
p coord[MAX];
vector<int> graph[MAX];
int dist(p x, p y) { return abs(x.first - y.first) + abs(x.second - y.second); }

void dfs(int now) {
    visited[now] = true;
    for (auto next : graph[now])
        if (!visited[next])
            dfs(next);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while (tc--) {
        for (int i = 0; i < MAX; ++i)
            graph[i].clear();
        memset(visited, false, sizeof(visited));
        
        cin >> N;
        
        for (int i = 0; i < N + 2; ++i) 
            cin >> coord[i].first >> coord[i].second;
        
        for(int i = 0; i <N + 2;++i)
            for (int j = i + 1; j < N + 2; ++j) 
                if (dist(coord[i], coord[j]) <= 20 * 50) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
           
        dfs(0);
        if (visited[N + 1])
            cout << "happy" << endl;
        else cout << "sad" << endl;
    }
    return 0;
}