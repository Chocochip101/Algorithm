#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1500001
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

int N;
int cache[MAX];
p schedule[MAX];
int solve(int now){
    if(now == N + 1) return 0;
    if(now > N + 1) return -INF;

    int & ret = cache[now];
    if(ret != -1) return ret;
    ret = 0;
    // 현재를 선택 / 다음 날짜
	ret += max(schedule[now].second + solve(now + schedule[now].first), solve(now + 1));
	
    return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> schedule[i].first >> schedule[i].second;
    cout << solve(1) << endl;
	return 0;
}