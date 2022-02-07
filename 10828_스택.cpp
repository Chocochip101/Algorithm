#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
stack<int> s;

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

		else if (str == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << s.top() << '\n';
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
			cout << s.top() << '\n';
			s.pop();
		}

	}
	return 0;
}