#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
typedef pair<int, int> p;
int main() {
	int n;
	cin >> n;
	vector<int> score(n);
	for (int i = 0; i < n; ++i)cin >> score[i];
	int res = 0;
	for (int i = n - 1; i > 0; --i) {
		if (score[i - 1] >= score[i]) {
			res += (score[i - 1] - score[i] + 1);
			score[i - 1] = score[i] - 1;
		}
	}
	cout << res << endl;
	return 0;
}