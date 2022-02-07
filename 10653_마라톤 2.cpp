#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 501
using namespace std;
typedef pair<int, int> p;

int N, K; 
p coord[MAX];
int cache[MAX][MAX];
int dist[MAX][MAX];
int solve(int idx, int ck) {
	if (idx == 0) return 0;
	int& ret = cache[idx][ck];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i <= ck; ++i)
		if(idx - i - 1 >= 0)
			ret = min(ret, solve(idx - 1 - i, ck - i) + dist[idx -1 -i][idx]);

	return ret;

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> coord[i].first >> coord[i].second;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			dist[i][j] = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);

	cout << solve(N - 1, K);
	return 0;
}