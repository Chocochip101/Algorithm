#include<bits/stdc++.h>
#define endl "\n"
#define MAX 11
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M;
string bb[MAX];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int totalSize = 0;
	
	for (int i = 0; i < N; ++i) {
		cin >>bb[i];
		totalSize += bb[i].size();
	}
	int bas = (M - totalSize) / (N - 1);
	int redBlank = (M - totalSize) % (N - 1);

	
	for (int i = 1; i < N; ++i) {
		if (redBlank > 0 && ('a' <= bb[i][0] && bb[i][0] <= 'z')) {
			bb[i] = '_' + bb[i];
			redBlank--;
		}
	}

	for (int i = N - 1; i > 0; --i) {
		if (redBlank > 0 && 'A' <= bb[i][0] && bb[i][0] <= 'Z') {
			bb[i] = '_' + bb[i];
			redBlank--;
		}
	}
	for (int i = 1; i < N; ++i)
		for (int j = 0; j < bas; ++j)
			bb[i] = '_' + bb[i];

	string ans = bb[0];
	for (int i = 1; i < N; ++i)
		ans += bb[i];
	cout << ans << endl;
	return 0;
}