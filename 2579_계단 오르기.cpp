#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int n;
int cache[301];
int stairs[301];
int stair(int i) {
	//Base
	if (i < 0) return 0;

	//Memoization
	int& ret = cache[i];
	if (ret != -1) return ret;
	ret = max(ret, stair(i - 2) + stairs[i]);
	ret = max(ret, stair(i - 3) + stairs[i - 1] + stairs[i]);

	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> stairs[i];
	memset(cache, -1, sizeof(cache));

	cout << stair(n - 1);
	return 0;
}
