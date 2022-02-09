#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000000
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int winRate(int x, int y) {
	return (y * 100) / x;
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, y; cin >> x >> y;



	int now = winRate(x, y);

	if (now >= 99) {
		cout << -1;
		return 0;
	}

	int ans = -1;
	int s = 0, e = 1000000000;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (winRate(x + mid, y + mid) > now) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
	return 0;
}