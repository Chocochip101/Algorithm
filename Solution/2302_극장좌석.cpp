#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 41
#define MOD 10007
using namespace std;

typedef pair<int,int> p;

int N, M;

int cache[MAX];
int solve(int idx){
    if(idx == 0 || idx == 1) return 1;
    int&ret = cache[idx];
    if(ret != -1) return ret;

    return ret = solve(idx - 1) + solve(idx - 2);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;

    int ans = 1;
    int prev = 0;
    for(int i = 0; i < M; ++i){
        int a; cin >> a;
        ans *= solve(a - prev - 1);
        prev = a;
    }
    ans *= solve(N - prev);
    cout << ans;

	return 0;
}