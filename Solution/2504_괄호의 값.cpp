#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1000001
using namespace std;
typedef pair<int, int> p;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	bool succeed = true;
	stack<char> stk;
	int res = 0, temp = 1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			stk.push('(');
			temp *= 2;
		}
		else if (s[i] == '[') {
			stk.push('[');
			temp *= 3;

		}
		else if (s[i] == ')' && (stk.empty() || stk.top() != '(')) {
			succeed = false;
			break;
		}
		else if (s[i] == ']' && (stk.empty() || stk.top() != '[')) {
			succeed = false;
			break;
		}
		else if (s[i] == ')') {
			if (s[i - 1] == '(')
				res += temp;
			stk.pop();
			temp /= 2;
		}
		else if (s[i] == ']') {
			if (s[i - 1] == '[')
				res += temp;
			stk.pop();
			temp /= 3;
		}
	}

	if (!succeed || !stk.empty())
		cout << 0;
	else
		cout << res;

	return 0;
}