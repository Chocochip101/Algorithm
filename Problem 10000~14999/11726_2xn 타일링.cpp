#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int cache[1001];

int solve(int n) {
	//Base
	if (n == 1) return 1;
	if (n == 2) return 2;

	//Memoization
	int& ret = cache[n];
	if (ret != -1) return ret;

	return cache[n] = (solve(n - 1) % 10007 + solve(n - 2) % 10007) % 10007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	cout << solve(n) << endl;


	return 0;
}