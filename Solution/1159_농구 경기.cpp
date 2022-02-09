#include<bits/stdc++.h>
#define endl "\n"
#define MAX 51
#define INF 987654321
#define MOD 10007
using namespace std;

int firstName[26] = {0, };
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;  cin >> N;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		firstName[s[0] - 'a']++;
	}
	vector<char> vc;
	for (int i = 0; i < 26; ++i)
		if (firstName[i] >= 5)
			vc.push_back(i + 'a');
	if (vc.empty())
		cout << "PREDAJA";
	else
		for (char a : vc)
			cout << a;
	return 0;
}