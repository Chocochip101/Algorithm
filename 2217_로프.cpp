#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int res = 0;
vector <int> weight;
bool compare(int x, int y) { return x > y; }
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int n; cin >> n;
	weight.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
	}
	sort(weight.begin(), weight.end(), compare);
	for (int i = 0; i < n; ++i) {
		if (res < weight[i] * (i + 1)) res = weight[i] * (i + 1);
	}
	cout << res << endl;
	return 0;
}