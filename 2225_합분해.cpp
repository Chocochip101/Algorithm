#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 1000000000
using namespace std;
typedef pair<int, int> p;


ll cache[201][201];

ll solve(int n, int k) {
	if (k == 1) return 1;
	if (k <= 0)return 0;
	ll& ret = cache[n][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= n; ++i) {
		ret += solve(n - i, k - 1) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));
	cout << solve(n, k) << endl;
	return 0;
}