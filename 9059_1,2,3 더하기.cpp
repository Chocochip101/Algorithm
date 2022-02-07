#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int solve(int n) {
	//Base
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3)return 4;

	//Top-Down
	return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;

	for (int i = 0; i < tc; ++i) {
		int n; cin >> n;
		cout << solve(n) << endl;
	}

	return 0;
}