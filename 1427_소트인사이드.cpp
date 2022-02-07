#include <bits/stdc++.h>
using namespace std;
bool compare(int x, int y) { return x > y; }

int main() {
	string s;
	cin >> s;
	vector<int> c;
	for (int i = 0; i < s.size(); ++i) c.push_back((int)s[i] - '0');
	sort(c.begin(), c.end(), compare);
	for (int i = 0; i < s.size(); ++i) cout << c[i];
	return 0;
}