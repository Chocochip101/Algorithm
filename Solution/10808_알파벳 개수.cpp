#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int cnt[26] = { 0, };
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i)
		cnt[s[i] - 'a']++;

	for (int i = 0; i < 26; ++i)
		cout << cnt[i] << " ";
	return 0;
}