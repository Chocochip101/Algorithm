#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int n, k, cache[101][100001];
p items[101];	//무게, 가치

int solve(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[item][capacity];
	if (ret != -1) return ret;

	//물건을 담지 않을 경우
	ret = solve(capacity, item + 1);

	//물건을 담을 경우
	if (capacity >= items[item].first)
		ret = max(ret, solve(capacity - items[item].first, item + 1) + items[item].second);

	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> items[i].first >> items[i].second;
	memset(cache, -1, sizeof(cache));
	cout << solve(k, 0) << endl;
	return 0;
}