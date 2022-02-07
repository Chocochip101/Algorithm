#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int n, l;
vector<int> leak;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> n >> l;

	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp;
		leak.push_back(temp);
	}

	sort(leak.begin(), leak.end());
	int pivot = leak[0];
	int res = 1;
	for (int i = 1; i < n; ++i) {
		if (leak[i] - pivot >= l) {
			++res;
			pivot = leak[i];
		}
	}
	cout << res << endl;
	return 0;
}