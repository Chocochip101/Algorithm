#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int> zero(41);
vector<int> one(41);

void solve(int n) {
	zero[0] = 1; one[0] = 0;
	zero[1] = 0; one[1] = 1;

	for (int i = 2; i < 41; i++) {
		zero[i] = zero[i - 2] + zero[i - 1];
		one[i] = one[i - 2] + one[i - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int i = 0; i < tc; ++i) {
		int n; cin >> n;
		solve(n);
		cout << zero[n] << " " << one[n] << endl;
	}

	return 0;
}