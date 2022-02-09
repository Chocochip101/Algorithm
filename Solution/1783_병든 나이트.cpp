#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int solve(int n, int m) {
	if (n == 1) return 1;
	else if (n == 2) return min(4, (m + 1) / 2);
	else if (n >= 3)
		if (m <= 6) return min(4, m);
		else return m - 2;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}