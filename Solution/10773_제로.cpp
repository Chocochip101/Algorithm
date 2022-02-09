#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int k;
long long sum = 0;
deque<int> stk;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k;
	int temp;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		if (temp == 0) stk.pop_back();
		else stk.push_back(temp);
	}
	while (!stk.empty()) {
		sum += stk.back();
		stk.pop_back();
	}
	cout << sum;
	return 0;
}