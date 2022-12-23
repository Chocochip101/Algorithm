#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define cubetype first
#define cnt second
using namespace std;
bool groupWord(string a) {
	int alpha[26];
	memset(alpha, 0, sizeof(alpha));
	a.erase(unique(a.begin(), a.end()), a.end());
	loop(i, a.length()) {
		alpha[(int)(a[i] - 'a')]++;
		if (alpha[(int)(a[i] - 'a')] == 2)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int n; cin >> n;
	int cnt = 0;
	loop(i, n) {
		string a; cin >> a;
		if (groupWord(a))
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}