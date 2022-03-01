#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1001
using namespace std;
typedef pair<int, int> p;

int N;
int arr[MAX];
int cache[MAX];
int solve(int idx){
    int&ret = cache[idx];
    if(ret != -1) return ret;
    ret = arr[idx];
    for(int i = idx + 1; i < N; ++i)
        if(arr[idx] < arr[i])
            ret = max(ret, solve(i) + arr[idx]);
    return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
	cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    int ans = -1;
    for(int i = 0; i < N; ++i)
        ans = max(ans, solve(i));
    cout << ans << endl;
	return 0;
}