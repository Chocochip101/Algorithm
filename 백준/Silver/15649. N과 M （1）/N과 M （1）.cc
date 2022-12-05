#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m;
bool flag[9];
int arr[9];

void solve(int idx) {

	if (idx == m) { 
		for (int i = 0; i < m; ++i)cout << arr[i]<<" ";
		cout << endl;
		return; 
	}

	for (int i = 1; i <= n; ++i) {
		if (!flag[i]) {
			flag[i] = true;
			arr[idx] = i;
			solve(idx + 1);
			flag[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	solve(0);
	return 0;
}
