#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> p;

int N;
int P[10001], cache[10001];
int solve(int res) {
	if (res == 0) return 0;
	int& ret = cache[res];
	if (ret != -1) return ret;

	ret = P[res];
	for(int i = 1; i <=res; ++i)
		ret = min(ret, solve(res - i) + P[i]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> P[i];
	memset(cache, -1, sizeof(cache));
	cout << solve(N);
	return 0;
}