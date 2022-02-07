#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int n;
int numbers[MAX];
int cache[MAX];
int solve(int idx) {
    if (idx >= n) return INF;
    if (idx == n - 1) return 0;
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 1; i <= numbers[idx]; i++)
        ret = min(ret, solve(idx + i) + 1);
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    memset(cache, -1, sizeof(cache));
    cout << solve(0) << endl;
    return 0;
}