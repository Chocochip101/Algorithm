#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n; int m;
vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; ++i)cin >> A[i];
	sort(A.begin(), A.end());
	cin >> m; int temp;
	for (int i = 0; i < m; ++i) {
		cin >> temp;
		cout << (int)binary_search(A.begin(), A.end(), temp) << endl;
	}
	return 0;
}