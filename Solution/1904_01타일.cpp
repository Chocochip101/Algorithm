#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int n;
	cin >> n;
	vector <int> v(n + 1);
	v[0] = 0; v[1] = 1; v[2] = 2;
	for (int i = 3; i < n + 1; ++i) {
		v[i] = v[i - 1] % 15746 + v[i - 2] % 15746;
	}
	cout << v[n] % 15746 << "\n";
	return 0;
}