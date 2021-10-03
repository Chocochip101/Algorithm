#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int ll
#define MAX  200002
#define MOD 998244353
using namespace std;
typedef pair<int, int> p;

int A[6], B[6];
//6 8
//2 6
int gcd(int a, int b) {
	if (b % a == 0) return a;
	return gcd(b % a, a);
}
 signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 6; ++i)
		cin >> A[i];
	for (int i = 0; i < 6; ++i)
		cin >> B[i];


	int wins = 0;
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			if (A[i] > B[j])
				wins++;
	int delim = gcd(wins, 36);
	cout << wins / delim << "/" << 36 / delim;
	return 0;
}