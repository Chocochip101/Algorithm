#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, n) for(int i = 0; i <n; ++i) 
#define ll long long
#define INF 987654321
#define MAX 301
using namespace std;
typedef pair<int, int> p;

bool pld(int n) {
	for (int b = 2; b <= 64; ++b) {
		int num = n;
		string s;

		while (num > 0) {
			s.push_back(num % b);
			num /= b;
		}

		string revS = s;
		reverse(s.begin(), s.end());
		if (s == revS)
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << pld(n) << endl;
	}

	return 0;
}