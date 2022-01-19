#include<bits/stdc++.h>
#define endl "\n"
#define MAX 51
#define INF 987654321
#define MOD 10007
using namespace std;

int N, M, H;
vector<int> blocks[MAX];
int cache[MAX][1001];
int solve(int idx, int parSum) {
	if (parSum == H) return 1;
	if (parSum > H) return 0;
	if (idx > N) return 0;

	int& ret = cache[idx][parSum];
	if (ret != -1) return ret;

	ret = 0;
	for (int next : blocks[idx])
		ret += solve(idx + 1, next + parSum) % MOD;
	ret += solve(idx + 1, parSum) % MOD;

	return ret % MOD;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));
	cin >> N >> M >> H;
	cin.ignore(1);
	for (int i = 1; i <= N; ++i) {
		string inpt;
		getline(cin, inpt);
		int temp = 0;
		for (int j = 0; j < inpt.size(); ++j) {
			if (inpt[j] == ' ') {
				blocks[i].push_back(temp);
				temp = 0;
			}
			else {
				temp *= 10;
				temp += (inpt[j] - '0');

			}
		}
		if (temp != 0)
			blocks[i].push_back(temp);
	}

	cout << solve(1, 0);
	return 0;
}