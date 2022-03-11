#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 1001
#define INF 987654321
using namespace std;
int N;
int arr[MAX];
int cache[MAX];
int solve(int idx){
    int&ret = cache[idx];
    if(ret != -1) return ret;

    ret = 1;
    for(int i = idx + 1; i < N; ++i)
        if(arr[idx] < arr[i])
            ret = max(ret, solve(i) + 1);

    return ret;
}
int main() {
	cin >> N;
    for(int i  = 0; i < N; ++i)
        cin >> arr[i];
    memset(cache, -1, sizeof(cache));

    int ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, solve(i));
    cout << ans << endl;
	return 0;
}