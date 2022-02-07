#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define cubetype first
#define cnt second
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int n, s; cin >> n >> s;
	vector<int> a;
	a.resize(n);
	loop(i, n) cin >> a[i];

	int start = 0, end = 0, partial_sum = 0;
	int ans = INF;
	while (end <= n) {
		if (partial_sum >= s) partial_sum -= a[start++];
		else if (end == n) break;
		else if (partial_sum < s) partial_sum += a[end++];
		if (partial_sum >= s) ans = min(ans, end - start);
	}
	if (ans == INF) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}