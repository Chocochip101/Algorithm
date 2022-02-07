#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
vector <int> chu;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int n; cin >> n;
	chu.resize(n);
	for (int i = 0; i < n; ++i) cin >> chu[i];

	sort(chu.begin(), chu.end());

	int target = 1;
	for (int i = 0; i < n; ++i) {
		if (target < chu[i]) break;
		target += chu[i];
	}
	cout << target << endl;
	return 0;
}