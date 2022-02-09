#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 1000000000

using namespace std;
ll cache[1000001];
ll solve(int n) {
	if (n == 1) return 0;
	else if (n == 2)return 1;
	ll& ret = cache[n];
	if (ret != -1) return ret;
	return ret = ((n - 1) * (solve(n - 1) % INF + solve(n - 2) % INF)) % INF;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);


	int n; cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n) << endl;
	return 0;
}