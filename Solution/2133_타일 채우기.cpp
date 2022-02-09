#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int n, cache[31];

int solve(int num) {
	if (num % 2 == 1) return 0;
	if (num == 0) return 1;
	if (num == 2) return 3;

	int& ret = cache[num];
	if (ret != -1) return ret;

	ret = 3 * solve(num - 2);
	for (int i = 4; i <= num; i++)
		ret += 2 * solve(num - i);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	memset(cache, -1, sizeof(cache));

	cout << solve(n) << endl;
	return 0;
}