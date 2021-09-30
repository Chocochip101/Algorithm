#include <bits/stdc++.h>
#define endl "\n"
#define MAX  50001
#define int long long
using namespace std;
typedef pair<int, int> p;


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		map<string, vector<string>> mp;
		for (int i = 0; i < n; ++i) {
			string a, b; cin >> a >> b;
			mp[b].push_back(a);
		}
		int res = 1;
		for (auto a = mp.begin(); a != mp.end(); ++a) {
			res *= (a->second.size() + 1);
		}
		cout << res - 1 << endl;
	}
	return 0;
}