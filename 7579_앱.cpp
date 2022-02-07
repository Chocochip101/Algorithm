#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 101
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M;
int cache[MAX][MAX * MAX];
int cost[MAX];
int memory[MAX];
int solve(int idx, int C) {
    if (idx == N) return 0;
    int& ret = cache[idx][C];
    if (ret != -1) return ret;

    //활성화
    ret = solve(idx + 1, C);

    //비활성화
    if (C >= cost[idx])
        ret = max(ret, solve(idx + 1, C - cost[idx]) + memory[idx]);
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; ++i)
        cin >> memory[i];
    for (int i = 0; i < N; ++i)
        cin >> cost[i];
    int C = 0;
    while (1) {
        if (solve(0, C) >= M)
            break;
        C++;
    }
    cout << C << endl;
    return 0;
}