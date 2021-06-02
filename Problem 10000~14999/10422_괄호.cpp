#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 5001
#define MOD 1000000007
using namespace std;

ll cache[MAX];
ll solve(int L) {
	if (L % 2 == 1) return 0;
	if (L == 0 || L == 2) return 1;

	ll& ret = cache[L];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 2; i <= L; i++) {
		ret += (solve(i - 2) * solve(L - i));
		ret %= MOD;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	memset(cache, -1, sizeof(cache));

	while (T--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}