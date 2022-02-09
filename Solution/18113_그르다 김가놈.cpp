#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000001
#define INF 987654321
#define ll long long
using namespace std;
typedef pair<int, int> p;

int N, K, M;
vector<int> rice;
int solve(int P) {
	int ret = 0;
	for (int i = 0; i < rice.size(); ++i)
		ret += rice[i] / P;
	return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> M;
	int s = 0, e = 0;
	for (int i = 0; i < N; ++i) {
		int a;  cin >> a;
		if (a >= 2 * K) {
			a -= 2 * K;
		}
		else if (a > K) {
			a -= K;
		}
		else
			a = 0;
		e = max(e, a);
		if (a > 0)
			rice.push_back(a);
	}

	int ans = -1;
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		// Div by Zero
		if (mid == 0) {
			s++;
			continue;
		}
		if (solve(mid) >= M) {
			ans = max(mid, ans);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans;
	return 0;
}