#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
queue<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int x; cin >> x;
			s.push(x);
		}

		else if (str == "front") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.front() << '\n';
		}
		else if (str == "back") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.back() << '\n';
		}
		else if (str == "size")
			cout << s.size() << "\n";

		else if (str == "empty")
			cout << s.empty() << "\n";

		else if (str == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.front() << '\n';
			s.pop();
		}

	}
	return 0;
}