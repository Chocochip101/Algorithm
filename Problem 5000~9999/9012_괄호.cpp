#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool wellMatched(const string& formula) {
	stack<char> stk;

	for (int i = 0; i < formula.size(); ++i) {
		if (formula[i] == '(') stk.push(formula[i]);
		else {
			if (stk.empty())return false;
			stk.pop();
		}
	}return stk.empty();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	string s;
	while (t--) {
		cin >> s;
		if (wellMatched(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}