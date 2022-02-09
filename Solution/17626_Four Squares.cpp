#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 50001
using namespace std;
typedef pair<int, int> p;

int N;
int cache[MAX];
int solve(int n) {
	if (n <= 0) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 1; i <= sqrt(n); ++i) {
		ret = min(ret, solve(n - i * i) + 1);
	}
	return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << solve(N);
	return 0;
}