#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 100001
#define INF 987654321
#define MOD 1000000009
#define int ll
using namespace std;
typedef pair<int, int> p;

int cache[MAX][4];
int solve(int k, int prev) {
    if (k == 0) return 1;
    int& ret = cache[k][prev];
    if (ret != -1) return ret;

    ret = 0;

    if (prev != 1 && k >= 1)
        ret += solve(k - 1, 1) % MOD;
    if (prev != 2 && k >= 2)
        ret += solve(k - 2, 2) % MOD;
    if (prev != 3 && k >= 3)
        ret += solve(k - 3, 3) % MOD;

    return ret % MOD;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    memset(cache, -1, sizeof(cache));
    while (tc--) {
        int k; cin >> k;
        cout << solve(k, 0) << endl;
    }
    return 0;
}