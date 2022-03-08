#include<bits/stdc++.h>
#define MAX 101
#define INF 987654321 
#define int long long
using namespace std;
typedef pair<int, int> p;
int N, K;
// time money
p walk[MAX];
p bycicle[MAX];
// idx, time = money
int cache[MAX][100001];
int solve(int now, int t){
    if(t > K) return -INF;
    if(now == N + 1) return 0;

    int &ret = cache[now][t];
    if(ret != -1) return ret;

    ret = solve(now + 1, t + walk[now].first) + walk[now].second;

    if(t + bycicle[now].first <= K)
        ret = max(ret, solve(now + 1, t + bycicle[now].first) + bycicle[now].second);

    return ret;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    for(int i = 1; i <= N; ++i)
        cin >> walk[i].first >> walk[i].second >> bycicle[i].first >> bycicle[i].second;

    cout << solve(1, 0);
    return 0;
}