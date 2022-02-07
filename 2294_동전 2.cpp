#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 10000+1
#define MOD 10007
using namespace std;

int coins[101];
int cache[MAX];
int n, k;

void solve() {
	memset(cache, 0, sizeof(cache));
	for (int i = 1; i <= k; ++i)
		cache[i] = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = coins[i]; j <= k; j++)
			cache[j] = min(cache[j], cache[j - coins[i]] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	solve();
	if (cache[k] == INF) cout << -1 << endl;
	else cout << cache[k] << endl;

	return 0;
}