#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MOD 9901
using namespace std;
typedef pair<int, int> p;


int cache[100001][3]; //0:¿Þ, 1:¿À, 2:¾øÀ½

int solve(int n) {
	cache[1][0] = cache[1][1] = cache[1][2] = 1;
	for (int i = 2; i <= n; ++i) {
		cache[i][0] = (cache[i - 1][1] + cache[i - 1][2]) % MOD;
		cache[i][1] = (cache[i - 1][0] + cache[i - 1][2]) % MOD;
		cache[i][2] = (cache[i - 1][0] + cache[i - 1][1] + cache[i - 1][2]) % MOD;
	}
	return (cache[n][0] + cache[n][1] + cache[n][2]) % MOD;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}