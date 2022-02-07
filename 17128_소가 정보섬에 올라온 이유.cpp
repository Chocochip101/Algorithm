#include<bits/stdc++.h>
#define endl "\n"
#define MAX 200001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, Q;
int cows[MAX];
int ans = 0;
// Memo Partial Sum
int parSum[MAX];
int idx(int i) {
	if (i <= -1) return N + i;
	else if (i >= N) return i - N;
	else return i;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	cin >> N >> Q;

	for (int i = 0; i < N; ++i)
		cin >> cows[i];


	for (int i = 0; i < N; ++i) {
		parSum[i] += (cows[i % N] * cows[(i + 1) % N] * cows[(i + 2) % N] * cows[(i + 3) % N]);
		ans += parSum[i];
	}

	for (int i = 0; i < Q; ++i) {
		int q; cin >> q;
		--q;
		for (int j = 0; j < 4; ++j) {
			parSum[idx(q - 3 + j)] *= -1;
			ans += (2 * parSum[idx(q - 3 + j)]);
		}
		cout << ans << endl;
	}
	return 0;
}