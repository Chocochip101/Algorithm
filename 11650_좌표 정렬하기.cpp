#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef pair<int, int> p;
vector<p> coord;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int n; cin >> n;
	coord.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> coord[i].first >> coord[i].second;
	sort(coord.begin(), coord.end());
	for (int i = 0; i < n; ++i)
		cout << coord[i].first << " " << coord[i].second << endl;

	return 0;
}