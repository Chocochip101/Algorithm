#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1010
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int J, N;
int box[MAX];
bool cmp(int a, int b) { return a > b; }
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc; cin >> tc;
	while (tc--) {
		cin >> J >> N;
		for (int i = 0; i < N; ++i) {
			int R, C; cin >> R >> C;
			box[i] = R * C;
		}

		sort(box, box + N, cmp);
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if (J <= 0) break;
			ans = i + 1;
			J -= box[i];
		}
		cout << ans << endl;
	}
	return 0;
}