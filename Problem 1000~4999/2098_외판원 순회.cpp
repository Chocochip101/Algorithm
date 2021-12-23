#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 16
using namespace std; 
typedef pair<int, double> p;

int N, adj[MAX][MAX];
int cache[MAX][1 << 16];
int solve(int now, int visited) {
    int& ret = cache[now][visited];
    if (ret != -1) return ret;

    //모든 마을 방문 후
    if (visited == (1 << N) - 1) {
        //돌아갈 수 있으면
        if (adj[now][0] != 0) 
            return adj[now][0];
        return INF;
    }


    ret = INF;
    //모든 마을 순회
    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i) || adj[now][i] == 0) continue;
        ret = min(ret, solve(i, visited | (1 << i)) + adj[now][i]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> adj[i][j];

    memset(cache, -1, sizeof(cache));
    cout << solve(0, 1);
    return 0;
}