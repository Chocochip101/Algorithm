#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int n;
deque<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "push") {
			int x; cin >> x;
			q.push_back(x);
		}
		else if (s == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (s == "size")
			cout << q.size() << "\n";
		else if (s == "empty")
			cout << q.empty() << "\n";
		else if (s == "front") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
			}
		}
		else if (s == "back") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
			}
		}


	}

	return 0;
}