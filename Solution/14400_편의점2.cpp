#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 100001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
int N; 
p coords[MAX];

bool cmp(p a, p b){
    return a.second < b.second;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> coords[i].first >> coords[i].second;

    sort(coords, coords + N);
    int x = coords[(N - 1) / 2].first;
    sort(coords, coords + N, cmp);
    int y = coords[(N - 1) / 2].second;
    int ans = 0;
    for(int i = 0; i < N; ++i)
        ans += (abs(x - coords[i].first) + abs(y - coords[i].second));
    cout << ans << endl;
    return 0;
}