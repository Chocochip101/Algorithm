#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 11
#define int ll
using namespace std;
typedef pair<int, int> p;

int res_min = INF;
int res_max = -INF;
int N, arr[MAX];
int oper[4];
void dfs(int total,int idx, int pp, int mi, int mul, int div) {
	if (idx == N) {
		res_min = min(res_min, total);
		res_max = max(res_max, total);
		return;
	}

	if (pp < oper[0])
		dfs(total + arr[idx], idx + 1, pp + 1, mi, mul, div);
	if (mi < oper[1])
		dfs(total - arr[idx ], idx + 1, pp , mi + 1, mul, div);
	if (mul < oper[2])
		dfs(total * arr[idx], idx + 1, pp , mi, mul + 1, div);
	if (div < oper[3])
		dfs(total / arr[idx], idx + 1, pp, mi, mul, div + 1);

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> oper[i];

	dfs(arr[0],1, 0, 0, 0, 0);
	cout << res_max << endl << res_min<< endl;
	return 0;
}