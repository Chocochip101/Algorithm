#include <bits/stdc++.h>
#define endl "\n"
#define MAX  31
#define int long long
using namespace std;
typedef pair<int, int> p;

int cache[MAX][MAX];
int solve(int w, int h) {
	if (w == 0) return 1;
	int& ret = cache[w][h];
	if (ret != -1) return ret;

	ret = 0;
	if (w > 0)
		ret += solve(w - 1, h + 1);
	
	if (h > 0)
		ret += solve(w, h - 1);

	return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(cache, -1, sizeof(cache));
	int n;
	while (1) {
		cin >> n; 
		if (n == 0) break;
		//W∑Œ Ω√¿€
		cout << solve(n - 1, 1) << endl;
	}
	return 0;
}