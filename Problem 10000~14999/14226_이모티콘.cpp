#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 3000
#define INF 987654321

using namespace std;
typedef pair<int, int> p;

int s;
int cache[MAX][MAX];

int solve(int now, int clip) {
    if (now > s * 2 || clip > s * 2) return INF;
    if (now < 0) return INF;
    if (now == s) return 0;

    int& ret = cache[now][clip];

    if (ret != -1) return ret;

    ret = INF;
    ret = min(ret, solve(now, now) + 1);
    ret = min(ret, solve(now + clip, clip) + 1);
    ret = min(ret, solve(now - 1, clip) + 1);
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    memset(cache, -1, sizeof(cache));

    cout << solve(1, 0);
    return 0;
}