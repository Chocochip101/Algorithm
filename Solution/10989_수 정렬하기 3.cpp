#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001] = { 0, };

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, temp;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> temp;
		arr[temp]++;
	}
	for (int i = 0; i < 10001; ++i)
		for (int j = 0; j < arr[i]; j++)
			cout << i << '\n';
	return 0;
}