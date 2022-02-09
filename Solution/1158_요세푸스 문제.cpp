#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, k;
vector<int> ans;
queue<int> q;
void solve() {
	int cnt = 0;
	while (!q.empty()) {
		if (cnt == k - 1) {
			ans.push_back(q.front());
			q.pop();
			cnt = 0;
		}
		else {
			q.push(q.front());
			q.pop();
			cnt++;
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) q.push(i);
	solve();
	cout << "<";
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
		if (i != n - 1) cout << ", ";
	}
	cout << ">" << endl;
	return 0;
}