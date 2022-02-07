#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;
deque<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int x; cin >> x;
			s.push_front(x);
		}
		else if (str == "push_back") {
			int x; cin >> x;
			s.push_back(x);
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

		else if (str == "pop_front") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.front() << '\n';
			s.pop_front();
		}
		else if (str == "pop_back") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.back() << '\n';
			s.pop_back();
		}
	}
	return 0;
}