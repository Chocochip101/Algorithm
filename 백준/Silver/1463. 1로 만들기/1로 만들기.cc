#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[1000001];

int main() {
	int n;
	cin >> n;

	cache[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		cache[i] = cache[i - 1] + 1;
		if (i % 3 == 0) cache[i] = min(cache[i / 3] + 1, cache[i]);
		if (i % 2 == 0) cache[i] = min(cache[i / 2] + 1, cache[i]);
	}
	cout << cache[n];
	return 0;
}