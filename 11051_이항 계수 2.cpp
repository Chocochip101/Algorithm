#include <iostream>
#include <algorithm>
using namespace std;

int cache[1000][1000];
int solve(int n, int k) {
	if (k == 0 || n == k) return 1;

	int& ret = cache[n][k];
	if (ret != 0) return cache[n][k];
	return ret = solve(n - 1, k - 1) % 10007 + solve(n - 1, k) % 10007;
}
int main() {
	int n, k;
	cin >> n >> k;

	cout << solve(n, k) % 10007;
	return 0;
}