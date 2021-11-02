#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 101
#define INF 987654321

using namespace std;
typedef pair<int, int> p;

int N, T;
int StudyTime[MAX];
int Score[MAX];
int cache[101][10001];
int solve(int idx, int T) {
    if (idx == N) return 0;
    int& ret = cache[idx][T];
    if (ret != -1)return ret;

    ret = solve(idx + 1, T);
    if (T >= StudyTime[idx])
        ret = max(ret, solve(idx + 1, T - StudyTime[idx]) + Score[idx]);
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> T;
    for (int i = 0; i < N; ++i)
        cin >> StudyTime[i] >> Score[i];

    memset(cache, -1, sizeof(cache));
    cout << solve(0, T);
    return 0;
}