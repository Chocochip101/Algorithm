#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std; 
typedef pair<int, double> p;

int cache[10001][101];
int solve(int n, int m) {
    if (n < 0 || m < 0) return INF;
    if (n % m == 0) return n / m;
    if (n == m) return 1;

    int& ret = cache[n][m];
    if (ret != -1) return ret;

    // 정사각형 최대 개수
    ret = n * m;
    if(n >= 4 * m)
        ret = min(ret, solve(n - m, m) + 1);
    for (int i = 1; i <= n / 2; ++i)
        ret = min(ret, solve(n - i, m) + solve(i, m));

    for (int j = 1; j <= m / 2; ++j)
        ret = min(ret, solve(n, m - j) + solve(n, j));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    int n, m; cin >> n >> m;
    cout << solve(n, m);
    return 0;
}