#include <bits/stdc++.h>
#define endl "\n"
#define MAX  1002
#define int long long
using namespace std;
typedef pair<int, int> p;

int N = 0;
int arr[MAX][2];
int cache[MAX][16][16];
int solve(int idx, int b_cnt, int w_cnt){
    if(idx == N) return 0;
    if(b_cnt == 15 && w_cnt == 15) return 0;

    int &ret = cache[idx][b_cnt][w_cnt];
    if(ret != -1) return ret;
    
    // Skip
    ret = max(ret, solve(idx + 1, b_cnt, w_cnt));
    // White
    if(w_cnt < 15)
        ret = max(ret, solve(idx + 1, b_cnt, w_cnt + 1) + arr[idx][0]);
    // Black
    if(b_cnt < 15)
        ret = max(ret, solve(idx + 1, b_cnt + 1, w_cnt) + arr[idx][1]);
    return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));

    int a, b;
    while(cin >> a >> b){
        arr[N][0] = a;
        arr[N][1] = b;
        N++;
    }
    cout << solve(0, 0, 0);
	return 0;
}