#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX  1001
#define MOD 998244353
using namespace std;
typedef pair<int, int> p;

int cache[500][200002];
int solve(int c, int n) {
	if (n < 0) return 0;
	if (c == 0) return n == 0;

	if (cache[c][n] != -1) return cache[c][n];

	ll ret = 0;
	ret += solve(c - 1, n);
	ret += solve(c, n - 2 * c);

	return cache[c][n] = ret % MOD;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));
	int tc; cin >> tc;

	while (tc--) {
		int n; cin >> n;
		ll ans = 0;
		for (int i = 1; i * i <= n; ++i) 
			ans += solve(i, n - i * i);
		
		cout << ans % MOD << endl;
	}
	return 0;
}