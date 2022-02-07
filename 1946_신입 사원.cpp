#include <bits/stdc++.h>
#define endl "\n"
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int tc; cin >> tc;
	for (int testcase = 0; testcase < tc; ++testcase) {
		int n; cin >> n;
		vector<p> num;
		for (int i = 0; i < n; ++i) {
			int a, b; cin >> a >> b;
			num.push_back(p(a, b));
		}
		sort(num.begin(), num.end());
		int min_num = num[0].y;
		int res = 0;
		for (int i = 1; i < n; ++i) {
			if (num[i].y > min_num)
				res++;
			else if (num[i].y < min_num) min_num = num[i].y;
		}
		cout << n - res << endl;
	}

	return 0;
}