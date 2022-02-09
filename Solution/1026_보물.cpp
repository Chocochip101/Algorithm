#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int n;
int a[51], b[51];
bool compare(int i, int j) { return i > j; }

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(a, a + n, compare);
	sort(b, b + n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[i];
	}
	cout << sum << endl;
	return 0;
}