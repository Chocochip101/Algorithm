#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 16
using namespace std;

struct nut {
	int p, f, s, v, c;
};

nut arr[MAX];
int N, mp, mf, ms, mv;
vector<int> temp;
vector<vector<int>> res;
int ans = INF;

void solve(int idx, int pro, int fat, int car, int vit, int total) {
	if (pro >= mp && fat >= mf && car >= ms && vit >= mv) {
		if (ans > total) {
			ans = total;
			res.clear();
			res.push_back(temp);
			return;
		}
		else if(ans == total) {
			res.push_back(temp);
			return;
		}
	}
	for (int i = idx + 1; i < N; ++i) {
		temp.push_back(i);
		solve(i, pro + arr[i].p, fat + arr[i].f, car + arr[i].s, vit + arr[i].v, total + arr[i].c);
		temp.pop_back();
		solve(i, pro, fat, car, vit, total);
	}
	
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;

	solve(-1, 0, 0, 0, 0, 0);
	sort(res.begin(), res.end());
	if (ans >= INF)
		cout << -1;
	else {
		cout << ans << endl;
		for (int a : res[0])
			cout << a + 1 << " ";
	}
	return 0;
}