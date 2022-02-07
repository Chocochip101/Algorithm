#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1001
using namespace std;
typedef pair<int, int> p;

int N;
bool T[MAX][10];
bool flag[MAX][10];
int ans[MAX];

bool dfs(int idx, int prev) {
	if(idx == N)
		return true;


	for (int now = 1; now < 10; ++now) {
		if (now != prev && T[idx][now] && !flag[idx + 1][now]) {
			flag[idx + 1][now] = true;
			ans[idx] = now;
			if (dfs(idx + 1, now)) return true;
		}
	}
	return false;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int m; cin >> m;
		for (int j = 0; j < m; ++j) {
			int temp; cin >> temp;
			T[i][temp] = true;
		}
	}

	if (dfs(0, 0))
		for (int i = 0; i < N; ++i)
			cout << ans[i]<<endl;
	else
	cout << -1;
	return 0;
}