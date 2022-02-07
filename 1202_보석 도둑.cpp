#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
typedef pair<int, int> p;
int main() {
	int n, k;
	cin >> n >> k;
	vector<p> jewerly(n);
	vector<int> bag(k);
	priority_queue<int> heap;
	for (int i = 0; i < n; ++i)
		cin >> jewerly[i].first >> jewerly[i].second;
	for (int i = 0; i < k; ++i)
		cin >> bag[i];

	sort(bag.begin(), bag.end());
	sort(jewerly.begin(), jewerly.end());
	ll res = 0;
	int jew_Idx = 0;
	for (int i = 0; i < k; ++i) {

		while (jew_Idx < n && jewerly[jew_Idx].first <= bag[i])
			heap.push(jewerly[jew_Idx++].second);

		if (!heap.empty()) {
			res += heap.top();
			heap.pop();
		}

	}

	cout << res << endl;
	return 0;
}