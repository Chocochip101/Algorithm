#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 50001
using namespace std;
typedef pair<int, int> p;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		multiset<int> q;
		int k; cin >> k;
		for (int i = 0; i < k; ++i) {
			char c; cin >> c;
			int n; cin >> n;
			if (c == 'I')
				q.insert(n);
			else {
				if (!q.empty() && n == 1) {
					auto iter = q.end();
					q.erase(--iter);
				}
				else if (!q.empty() && n == -1) {
				
					q.erase(q.begin());
				}
			}
		}

		if (q.empty())
			cout << "ERASE" << endl;
		else {
			auto iter = q.end();
			--iter;
			cout << *iter << " " << *q.begin()<< endl;
		}

	}
	return 0;
}