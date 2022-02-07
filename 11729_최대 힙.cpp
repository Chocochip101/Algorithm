#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	priority_queue<int> heap;
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp;
		if (temp != 0) heap.push(temp);
		else {
			if (heap.empty()) cout << 0 << endl;
			else {
				cout << heap.top() << endl;
				heap.pop();
			}
		}
	}
	return 0;
}