#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
using namespace std;
typedef pair<int, int> p;

int bb[5][15];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(bb, -1, sizeof(bb));
	for (int i = 0; i < 5; ++i) {
		string temp; cin >> temp;
		for (int j = 0; j < temp.size(); ++j)
			bb[i][j] = temp[j];

	}

	for (int j = 0; j < 15; ++j) {
		for (int i = 0; i < 5; ++i)
			if (bb[i][j] != -1)
				cout << (char)bb[i][j];
	}
	return 0;
}