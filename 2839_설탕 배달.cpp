#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int n;

int main() {
	cin >> n;
	vector <long long> dp(5001, INF);

	//Base
	dp[3] = 1, dp[5] = 1;

	//Bottom-Up
	for (int i = 6; i < n + 1; ++i) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}

	if (dp[n] >= INF) cout << -1 << "\n";
	else cout << dp[n] << "\n";

	return 0;
}
