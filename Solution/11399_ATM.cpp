#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int n;
int a[1001];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (n - i) * a[i];
	}
	cout << sum << endl;
	return 0;
}