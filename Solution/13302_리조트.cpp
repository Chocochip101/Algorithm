#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M;
bool canGo[MAX];
int cache[MAX][303];
int solve(int now, int coup) {
	if (now > N) return 0;
	int& ret = cache[now][coup];
	if (ret != -1) return ret;
	ret = INF;
	if (canGo[now]) {

		// 쿠폰
		if (coup >= 3)
			ret = min(ret, solve(now + 1, coup - 3));
            
        // 하루권
		ret = min(ret, solve(now + 1, coup) + 10000);

		// 3일권
		ret = min(ret, solve(now + 3, coup + 1) + 25000);

		// 5일권
		ret = min(ret, solve(now + 5, coup + 2) + 37000);
	}
	else {
		ret = min(ret, solve(now + 1, coup));
	}

	return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	memset(canGo, true, sizeof(canGo));
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a; cin >> a;
		canGo[a] = false;
	}
	cout << solve(1, 0);
	return 0;
}