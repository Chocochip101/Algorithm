#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define cubetype first
#define cnt second
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	bitset<21> bit;
	bit.reset();

	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		if (s == "add") {
			int a; cin >> a;
			bit.set(a, true);
		}
		else if (s == "remove") {
			int a; cin >> a;
			bit.set(a, false);
		}
		else if (s == "check") {
			int a; cin >> a;
			cout << bit[a] << endl;
		}
		else if (s == "toggle") {
			int a; cin >> a;
			if (bit[a])bit.set(a, false);
			else bit.set(a, true);
		}
		else if (s == "all") {
			bit.set();
		}
		else if (s == "empty") {
			bit.reset();
		}
	}
	return 0;
}