#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
typedef pair<int, int> p;
int solve(int a, int b) {
	int res = 0;
	while (b > 0) {
		if (a == b) break;
		if (b % 2 == 0) {
			res++;
			b /= 2;
			continue;
		}
		if (b % 10 == 1) {
			res++;
			b /= 10;
			continue;
		}
		else {
			res = -1;
			break;
		}
	}
	if (a != b) res = -1;
	return res;
}
int main() {
	int a, b;
	cin >> a >> b;
	int res = solve(a, b);
	if (res == -1) cout << -1 << endl;
	else cout << res + 1 << endl;
	return 0;
}