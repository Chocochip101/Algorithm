#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int R, C, K;
int parSum[MAX][MAX];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			int num;  cin >> num;
			parSum[i + 1][j + 1] = num + parSum[i + 1][j] + parSum[i][j + 1] - parSum[i][j];
		}
	

	for (int i = 0; i < K; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (parSum[x2][y2] - parSum[x1 - 1][y2] - parSum[x2][y1 - 1] + parSum[x1 - 1][y1 - 1]) / ((x2 - x1 + 1) * (y2 - y1 + 1)) << endl;
	}

	return 0;
}