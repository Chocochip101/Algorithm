#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, n) for(int i = 0; i <n; ++i)
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int l; cin >> l;
	vector<int> s(l);
	loop(i, l) cin >> s[i];
	int n; cin >> n;
	sort(s.begin(), s.end());
	int left, right;
	int res = 0;
	loop(i, l) {
		if (s[i] == n) { cout << 0 << endl; return 0; }
		if (s[i] > n) { left = s[i - 1] + 1; right = s[i] - 1; break; }
	}
	for (int i = min(left, n); i <= n; ++i) {
		for (int j = n; j <= right; ++j) {
			res++;
		}
	}cout << res - 1 << endl;
	return 0;
}