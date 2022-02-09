#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
	string s;
	cin >> s;
	s.erase(unique(s.begin(), s.end()), s.end());
	int One = 0;
	int Zero = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') One++;
		if (s[i] == '1') Zero++;
	}
	cout << min(Zero, One) << endl;
	return 0;
}