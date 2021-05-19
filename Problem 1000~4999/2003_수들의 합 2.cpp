#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define cubetype first
#define cnt second
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a;
	a.resize(n);
	loop(i, n) cin >> a[i];

	int start = 0, end = 0, partial_sum = 0;
	int ans = 0;
	while (end <= n) {
		if (partial_sum >= m) partial_sum -= a[start++];
		else if (partial_sum < m) partial_sum += a[end++];
		if (partial_sum == m) ans++;
	}
	cout << ans << endl;
	return 0;
}