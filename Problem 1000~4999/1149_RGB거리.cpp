#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cache[1001][3];
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> cache[i][j];

	for (int i = 1; i < n; ++i) {
		cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + cache[i][0];
		cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + cache[i][1];
		cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + cache[i][2];
	}

	cout << min({ cache[n - 1][0], cache[n - 1][1], cache[n - 1][2] }) << endl;
	return 0;
}