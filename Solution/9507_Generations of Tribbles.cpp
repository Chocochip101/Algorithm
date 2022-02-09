#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 101
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
int cache[MAX];

int solve(int n) {
    if (n < 2) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    int& ret = cache[n];
    if (ret != -1) return ret;
    return ret = solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    memset(cache, -1, sizeof(cache));
    while (tc--) {
        int a; cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}