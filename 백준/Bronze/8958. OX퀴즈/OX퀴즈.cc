#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 26
using namespace std;
typedef pair<int, int> p;


int solve(string s) {
	int ans = 0;
	int temp = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'O') { temp++; ans += temp; }
		else {
			temp = 0;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t; 
	while (t--) {
		string s; cin >> s;
		cout << solve(s) << endl;
	}
	
	return 0;
}