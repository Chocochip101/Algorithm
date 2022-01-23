#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
int A[MAX];
int ans = 0;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A, A + N);


	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			int total = A[i] + A[j];
			ans += (upper_bound(A + j + 1, A + N, (-1) * total) - lower_bound(A + j + 1, A + N, (-1) * total));

		}
	}
	cout << ans << endl;
	return 0;
}