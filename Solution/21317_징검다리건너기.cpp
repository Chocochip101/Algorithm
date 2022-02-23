#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 21
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
p jumpEnergy[MAX];
int cache[MAX][2];
int K;

int solve(int idx, int usedMegaJump){
    if(idx == N) return 0;
    if(idx > N) return INF;
    int &ret = cache[idx][usedMegaJump];
    if(ret !=  -1) return ret;

    ret = INF;
    // Small Jump
    ret = min(ret, solve(idx + 1, usedMegaJump) + jumpEnergy[idx].first);
    // Big Jump
    ret = min(ret, solve(idx + 2, usedMegaJump) + jumpEnergy[idx].second);
    // Mega Jump
    if(usedMegaJump == 0)
        ret = min(ret, solve(idx + 3, 1) + K);
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    memset(cache, -1, sizeof(cache));

    for(int i = 1; i <= N - 1; ++i)
        cin >> jumpEnergy[i].first >> jumpEnergy[i].second;
    
    cin >> K;

    cout << solve(1, 0) << endl;
	return 0;
}