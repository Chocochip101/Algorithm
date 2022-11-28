#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 20000
#define MOD 100000
#define int ll
using namespace std;
typedef pair<int, int> p;

int A[MAX], B[MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		for (int i = 0; i < a; ++i) cin >> A[i];
		for (int i = 0; i < b; ++i)cin >> B[i];

		sort(A, A + a);
		sort(B, B + b);

		int res = 0;
		int idx = 0;
		for (int i = 0; i < a; ++i) {
			while (B[idx] < A[i] && idx < b) idx++;
			res += idx;
		}
		cout << res << endl;
	}
	return 0;
}