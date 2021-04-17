#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> q;

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp;
		q.push(temp);
	}
	int res = 0;
	int a, b;
	while (q.size() > 1) {
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		res += (a + b);
		q.push(a + b);
	}
	cout << res << endl;
	return 0;
}