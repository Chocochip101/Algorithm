#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1001
#define int ll
using namespace std;
typedef pair<int, int> p;
int H, N;
int cache[MAX][MAX];
int solve(int x, int y){
    if(x == H && y == H) return 1;
    if(y > x) return 0;
    if(x < H || y < H) return 0;

    int&ret = cache[x][y];
    if(ret != -1) return ret;

    return ret = solve(x - 1, y) + solve(x, y - 1);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> H >> N;
    if(H > N) swap(H, N);
    cout << solve(N, N) << endl;
	return 0;
}