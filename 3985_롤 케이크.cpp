#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int l, n;
	cin >> l >> n;
	vector<int> cake(l + 1, -1);
	vector<int> eat(n + 1, 0);
	int res = 0; int number = -1;
	for (int i = 1; i <= n; ++i) {
		int p, k;
		cin >> p >> k;
		if (k - p > res) {
			res = k - p;
			number = i;
		}
		for (int j = p; j <= k; ++j) {
			if (cake[j] == -1) {
				eat[i]++;
				cake[j] = i;
			}
		}
	}
	cout << number << endl;
	cout << max_element(eat.begin(), eat.end()) - eat.begin() << endl;
	return 0;
}

