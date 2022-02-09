#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 501
using namespace std;
typedef pair<int, int> p;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string B; int N;
	cin >> B >> N;
	int ans = 0;
	for (int i = 0; i < B.size(); ++i) {
		if ( '0' <= B[i] && B[i] <= '9')
			ans += pow(N, B.size() - i - 1) * (B[i] - '0');
		else if ('A' <= B[i] && B[i] <= 'Z')
			ans += pow(N, B.size() - i - 1) * (10 + B[i] - 'A');
	}
	cout << (int)ans;
	return 0;
}