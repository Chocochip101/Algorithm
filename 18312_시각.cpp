#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 501
using namespace std;
typedef pair<int, int> p;

int N, K; 

bool flag(int num) {

	if (num % 10 == K || num / 10 == K)
		return true;
	return false;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	int ans = 0;
	for (int h = 0; h <= min(N, 23); h++)
		for (int m = 0; m <= 59; ++m)
			for (int s = 0; s <= 59; ++s)
				if (flag(h) || flag(m) || flag(s))
					ans++;
	cout << ans;

	return 0;
}