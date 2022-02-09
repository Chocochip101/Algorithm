#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	priority_queue<ll, vector<ll>, greater<ll>> heap;
	int n, m;
	cin >> n >> m;
	ll temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		heap.push(temp);
	}
	ll a, b;
	for (int i = 0; i < m; ++i) {
		a = heap.top(); heap.pop();
		b = heap.top(); heap.pop();
		heap.push(a + b); heap.push(a + b);
	}
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += heap.top();
		heap.pop();
	}
	cout << sum << endl;
	return 0;
}