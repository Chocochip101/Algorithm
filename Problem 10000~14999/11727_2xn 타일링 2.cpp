#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1000+1
#define MOD 10007
using namespace std;

ll cache[MAX];
ll solve(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	ll& ret = cache[n];
	if (ret != -1)return ret;
	return ret = (solve(n - 1) % MOD + 2 * solve(n - 2) % MOD) % MOD;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n) << endl;
	return 0;
}