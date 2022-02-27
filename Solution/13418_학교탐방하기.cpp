#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1001
#define int ll
using namespace std;
typedef pair<int, int> p;
struct coords{
    int a, b, c;
};
int N, M;
vector<coords> graph;
int parent[MAX];
bool cmp1(coords a, coords b){
    return a.c < b.c;
}
bool cmp2(coords a, coords b){
    return a.c > b.c;
}
int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}
int kruskal(){
    for(int i = 0; i <= N; ++i)
        parent[i] = i;
    int ans = 0, cnt = 0;
    for(auto a : graph){
        if(find(a.a) != find(a.b)){
            merge(a.a, a.b);
            if(a.c == 0) ans++;
            if(++cnt == N) break;
        }
    }
    return ans * ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M + 1; ++i){
        int a, b, c; cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }

    sort(graph.begin(), graph.end(), cmp1);
    int ans = kruskal();
    sort(graph.begin(), graph.end(), cmp2);
    ans -= kruskal();

    cout << ans << endl;
	return 0;
}