#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 31
using namespace std;
int N;
string s;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> s;
	int cnt_B = 0, cnt_R = 0;
	for(int i = 0; i <s.size(); ++i)
		if (s[i] == 'B') {
			cnt_B++;
		}
		else {
			cnt_R++;
		}

	s.erase(unique(s.begin(), s.end()), s.end());
	int cnt_BB = 0, cnt_RR = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'B') {
			cnt_BB++;
		}
		else {
			cnt_RR++;
		}

	cout << min(1 + cnt_RR, 1 + cnt_BB);
	return 0;
}