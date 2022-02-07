#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector <int> v;

	int n;
	cin >> n;

	if (n % 2 == 1) {
		for (int i = 0; i < n - 1; ++i) {
			if (i % 2 == 0) v.push_back(1);
			else v.push_back(2);
		}
		v.push_back(3);
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) v.push_back(1);
			else v.push_back(2);
		}
	}
	for (int i = 0; i < n; ++i) cout << v[i] << " ";
	return 0;
}
