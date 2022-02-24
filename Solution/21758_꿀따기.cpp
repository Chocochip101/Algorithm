#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
int Honey[MAX];
int parSum[MAX];
signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i = 1; i <= N; ++i){
        cin >> Honey[i];
        parSum[i] = Honey[i] + parSum[i - 1];
    }
    int ans = 0;
    // 벌 벌 꿀
    for(int i = 2; i < N; ++i)
        ans = max(ans, parSum[N] - Honey[1] + parSum[N] - parSum[i] - Honey[i]);
    
    // 벌 꿀 벌
    for(int i = 2; i < N; ++i)
        ans = max(ans, parSum[i] - Honey[1] + parSum[N] - parSum[i - 1] - Honey[N]);

    // 꿀 벌 벌
    for(int i = 2; i < N; ++i)
        ans = max(ans, parSum[N] - Honey[N] + parSum[i] - Honey[i] - Honey[i]);
    cout << ans << endl;
	return 0;
}