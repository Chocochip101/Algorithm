#include<bits/stdc++.h>
#define endl "\n"
#define MAX 200001
#define int long long
using namespace std;
typedef pair<int, int> p;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	while (1) {
		getline(cin, s);
		if (s == "END") break;
		for (int i = 0; i < s.size(); ++i)
			cout << s[s.size() - i - 1];
		cout << endl;
	}
	
	return 0;
}