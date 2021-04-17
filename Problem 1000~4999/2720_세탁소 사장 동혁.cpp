#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
void solve(int n) {
	cout << n / 25 << ' ';
	n %= 25;
	cout << n / 10 << ' ';
	n %= 10;
	cout << n / 5 << ' ';
	n %= 5;
	cout << n << endl;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		solve(n);
	}
}