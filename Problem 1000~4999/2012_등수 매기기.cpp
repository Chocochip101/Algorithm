#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, n) for(int i = 0; i <n; ++i) 
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> rank(n);
	loop(i, n) cin >> rank[i];
	sort(rank.begin(), rank.end());
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res += abs(rank[i - 1] - i);
	}cout << res << endl;
	return 0;
}
