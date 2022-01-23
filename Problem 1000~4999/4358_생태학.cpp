#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<string, double> p;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	map<string, float> mp;
	string s;
	float total = 0;
	while (getline(cin, s)) {

		total++;
		if (mp.find(s) != mp.end()) {
			mp[s] += 1;
		}
		else
			mp[s] = 1;
	}
	cout << fixed;
	cout.precision(4);
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		cout << iter->first << " " << (iter->second / total) * 100 << endl;
	}
	
	return 0;
}