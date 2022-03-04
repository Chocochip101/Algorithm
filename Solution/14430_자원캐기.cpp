#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 301
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
int N, M; 
int board[MAX][MAX];
int cache[MAX][MAX];
bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
int solve(int x, int y){
    if(!valid(x, y)) return 0;
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(solve(x + 1, y), solve(x, y + 1)) + board[x][y];
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> board[i][j];

    cout << solve(0, 0);
    return 0;
}