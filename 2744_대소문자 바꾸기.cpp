#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 31
using namespace std;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	

	string s;
	cin >> s;
	int diff = 'a' - 'A';
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		if ('a' <= s[i] && s[i] <= 'z')
			ans += (char)(s[i] - diff);
		else
			ans += (char)(s[i] + diff);
	}
	cout << ans;
	return 0;
}